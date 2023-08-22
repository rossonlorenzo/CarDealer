#include "editwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>


#include "typeselector.h"
#include "productEditor/sedaneditor.h"
#include "productEditor/supercareditor.h"
#include "productEditor/suveditor.h"
#include "productEditor/productinjector.h"


namespace View {

EditWidget::EditWidget(
      MainWindow* main_window,
      products::List<const products::Car*>* items,
      const products::Car* subject
    )
    : main_window(main_window), items(items), subject(subject)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setObjectName("widget-edit");
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    status = new QLabel("Ready");
    status->setObjectName("Status");
    vbox->addWidget(status);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("properties-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    vbox->addLayout(form);

    id_input = new QSpinBox();
    id_input->setObjectName("id-input");
    id_input->setMinimum(1);
    id_input->setMaximum(INT_MAX);
    if (subject != nullptr) {
        id_input->setValue(subject->getId());
    }
    form->addRow("id :", id_input);

    name_input = new QLineEdit();
    name_input->setObjectName("name-input");
    if (subject != nullptr) {
        name_input->setText(QString::fromStdString(subject->getName()));
    }
    form->addRow("name :", name_input);

    brand_input = new QLineEdit();
    brand_input->setObjectName("brand-input");
    if (subject != nullptr) {
        brand_input->setText(QString::fromStdString(subject->getBrand()));
    }
    form->addRow("brand :", brand_input);

    list_price_input = new QSpinBox();
    list_price_input->setObjectName("list_price_input");
    list_price_input->setMinimum(0);
    list_price_input->setMaximum(INT_MAX);
    if (subject != nullptr) {
        list_price_input->setValue(subject->getList_price());
    }
    form->addRow("list price :", list_price_input);

    horsepower_input = new QSpinBox();
    horsepower_input->setObjectName("horsepower_input");
    horsepower_input->setMinimum(0);
    horsepower_input->setMaximum(INT_MAX);
    if (subject != nullptr) {
        horsepower_input->setValue(subject->getHorses());
    }
    form->addRow("horsepower :", horsepower_input);

    kilometers_input = new QSpinBox();
    kilometers_input->setObjectName("kilometers_input");
    kilometers_input->setMinimum(0);
    kilometers_input->setMaximum(INT_MAX);
    if (subject != nullptr) {
        kilometers_input->setValue(subject->getKilo());
    }
    form->addRow("kilometers :", kilometers_input);

    doors_input = new QCheckBox();
    doors_input->setObjectName("doors_input");
    doors_input->setChecked(false);
    if (subject != nullptr) {
        doors_input->setChecked(subject->getDoors());
    }
    form->addRow("doors :", doors_input);

    QHBoxLayout* image_selector = new QHBoxLayout();
    image_selector->setObjectName("image-selector");
    image_selector->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    form->addRow("image :", image_selector);

    image_path_input = new QLineEdit();
    image_path_input->setObjectName("image-input");
    if (subject != nullptr) {
        image_path_input->setText(QString::fromStdString(subject->getImage()));
    }
    image_selector->addWidget(image_path_input);

    QPushButton* select_image_button = new QPushButton("Select");
    select_image_button->setObjectName("select-image-button");
    image_selector->addWidget(select_image_button);

    QComboBox* type_input = new QComboBox();
    type_input->setObjectName("type-input");
    type_input->addItem("sedan");
    type_input->addItem("super car");
    type_input->addItem("suv");
    if (subject != nullptr) {
        TypeSelector type_selector(type_input);
        subject->accept(type_selector);
    }
    form->addRow("type :", type_input);

    stacked_editor = new QStackedLayout();
    vbox->addLayout(stacked_editor);

    PEditor::sedanEditor* sedan_editor = new PEditor::sedanEditor();
    stacked_editor->addWidget(sedan_editor);
    editors.push_back(sedan_editor);

    PEditor::superCarEditor* super_car_editor = new PEditor::superCarEditor();
    stacked_editor->addWidget(super_car_editor);
    editors.push_back(super_car_editor);

    PEditor::suvEditor* suv_editor = new PEditor::suvEditor();
    stacked_editor->addWidget(suv_editor);
    editors.push_back(suv_editor);

    if (subject != nullptr) {
        PEditor::PInjector p_injector(
            *sedan_editor,
            *super_car_editor,
            *suv_editor
        );
        subject->accept(p_injector);
    }
    showType(type_input->currentIndex());

    vbox->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setObjectName("actions");
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(actions);

    actions->addStretch();

    QPushButton* apply_button = new QPushButton("Apply");
    apply_button->setObjectName("apply");
    actions->addWidget(apply_button);

    QPushButton* cancel_button = new QPushButton("Cancel");
    cancel_button->setObjectName("cancel");
    actions->addWidget(cancel_button);

    // Connects signals
    connect(select_image_button, &QPushButton::clicked, this, &EditWidget::selectImage);
    connect(type_input, qOverload<int>(&QComboBox::currentIndexChanged), this, &EditWidget::showType);
    connect(apply_button, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancel_button, &QPushButton::clicked, main_window, &MainWindow::deploy);
}

void EditWidget::selectImage() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Select image",
        "./",
        "Image files (*.jpg *.jpeg *.png)"
    );
    if (path.isEmpty()) {
        return;
    }
    image_path_input->setText(path);
}

void EditWidget::showType(int index) {
    stacked_editor->setCurrentIndex(index);
}

void EditWidget::apply() {
    unsigned int id = id_input->value();
    QString name = name_input->text();
    QString brand = brand_input->text();
    int list_price = list_price_input->value();
    int horsepower = horsepower_input->value();
    int kilometers = kilometers_input->value();
    bool doors = doors_input->isChecked();
    QString image_path = image_path_input->text();
    PEditor::CarEditor* editor = editors[stacked_editor->currentIndex()];
    products::Car* product = editor->create(id, name, brand, list_price, horsepower, kilometers, doors, image_path);
    for (
        products::List<const products::Car*>::const_Iterator it=items->begin(); it!=items->end();
        it++
    ){
        if((*it)->getId() == id && (*it)!=subject){
               status->setText("Id already existing");
               return;
        }
    }

    items->remove(subject);
    items->add(product);
    main_window->reloadData();
    main_window->deploy();
}

}
