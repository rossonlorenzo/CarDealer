#include "card.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

#include "../../products/suv.h"
#include "../../products/sedan.h"
#include "../../products/supercar.h"


namespace View {
namespace ProductRender {

void Card::visit(const products::Suv& sv) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-suv");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(sv.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* id = new QLabel(QString::number(sv.getId()));
    id->setObjectName("id");
    id->setWordWrap(true);
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(sv.getBrand()+ " "+sv.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SUV"));
    type->setObjectName("type");
    vbox->addWidget(type);
}

void Card::visit(const products::Sedan& se) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-sedan");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(se.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* id = new QLabel(QString::number(se.getId()));
    id->setObjectName("id");
    id->setWordWrap(true);
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(se.getBrand()+ " "+se.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SEDAN"));
    type->setObjectName("type");
    vbox->addWidget(type);
}

void Card::visit(const products::Super_car& sc) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-supercar");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(sc.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* id = new QLabel(QString::number(sc.getId()));
    id->setObjectName("id");
    id->setWordWrap(true);
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(sc.getBrand()+ " "+sc.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SUPER CAR"));
    type->setObjectName("type");
    vbox->addWidget(type);
}

QWidget* Card::getWidget() const {
    return widget;
}

QPushButton* Card::getViewButton() const {
    return view_button;
}

QPushButton* Card::getEditButton() const {
    return edit_button;
}

QPushButton* Card::getDeleteButton() const {
    return delete_button;
}

}
}
