#include "listproducts.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "../../products/suv.h"
#include "../../products/sedan.h"
#include "../../products/supercar.h"

namespace View {
namespace ProductRender {

ListProducts::ListProducts()
    : has_controls(true)
{
}

void ListProducts::visit(const products::Suv& sv) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-suv");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(sv.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* id = new QLabel(QString::number(sv.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(sv.getBrand()+ " "+sv.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SUV"));
    type->setObjectName("type");
    vbox->addWidget(type);

    QHBoxLayout* details = new QHBoxLayout();
        details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(details);

        QLabel* evaluetion = new QLabel("evaluetion : " + QString::fromStdString(std::string(1,sv.evaluetion())));
        type->setObjectName("evaluetion");
        vbox->addWidget(evaluetion);

        QLabel* price = new QLabel("price : " + QString::number(sv.finalPrice()) + "€");
        price->setObjectName("price");
        details->addWidget(price);

        details->addStretch();
    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

void ListProducts::visit(const products::Sedan& se) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-sedan");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(se.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* id = new QLabel(QString::number(se.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(se.getBrand()+ " "+se.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SEDAN"));
    type->setObjectName("type");
    vbox->addWidget(type);

    QHBoxLayout* details = new QHBoxLayout();
        details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(details);
        QLabel* evaluetion = new QLabel("evaluetion : " + QString::fromStdString(std::string(1,se.evaluetion())));
        type->setObjectName("evaluetion");
        vbox->addWidget(evaluetion);

        QLabel* price = new QLabel("price : " + QString::number(se.finalPrice()) + "€");
        price->setObjectName("price");
        details->addWidget(price);

        details->addStretch();
    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

void ListProducts::visit(const products::Super_car& sc) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-supercar");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(sc.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* id = new QLabel(QString::number(sc.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);
    QLabel* name = new QLabel(QString::fromStdString(sc.getBrand()+ " "+sc.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);
    QLabel* type = new QLabel(QString::fromStdString("SUPER CAR"));
    type->setObjectName("type");
    vbox->addWidget(type);

    QHBoxLayout* details = new QHBoxLayout();
        details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(details);

        QLabel* evaluetion = new QLabel("evaluetion : " + QString::fromStdString(std::string(1,sc.evaluetion())));
        type->setObjectName("evaluetion");
        vbox->addWidget(evaluetion);

        QLabel* price = new QLabel("price : " + QString::number(sc.finalPrice()) + "€");
        price->setObjectName("price");
        details->addWidget(price);

        details->addStretch();
    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/view.png")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

bool ListProducts::hasControls() const {
    return has_controls;
}

void ListProducts::setHasControls(const bool has_controls) {
    this->has_controls = has_controls;
}

QWidget* ListProducts::getWidget() const {
    return widget;
}

QPushButton* ListProducts::getViewButton() const {
    return view_button;
}

QPushButton* ListProducts::getEditButton() const {
    return edit_button;
}

QPushButton* ListProducts::getDeleteButton() const {
    return delete_button;
}

}
}
