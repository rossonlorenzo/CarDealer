#include "full.h"

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

void Full::visit(const products::Suv& sv) {
    widget = new QWidget();
    widget->setObjectName("full-suv");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* id = new QLabel(QString::number(sv.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);

    QLabel* name = new QLabel("name : "+ QString::fromStdString(sv.getBrand() +" "+sv.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(sv.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(300, 300, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* list_price = new QLabel("list price : "+ QString::number(sv.getList_price()));
    list_price->setObjectName("list price");
    list_price->setWordWrap(true);
    details->addWidget(list_price);

    QLabel* horsepower = new QLabel("horsepower : "+ QString::number(sv.getHorses()));
    horsepower->setObjectName("horsepower");
    horsepower->setWordWrap(true);
    details->addWidget(horsepower);

    QLabel* kilo = new QLabel("kilometers : "+ QString::number(sv.getKilo()));
    kilo->setObjectName("kilometers");
    kilo->setWordWrap(true);
    details->addWidget(kilo);

    QLabel* doors = new QLabel("doors : "+ QString::fromStdString(sv.getDoors() ? "4" : "2"));
    doors->setObjectName("doors");
    doors->setWordWrap(true);
    details->addWidget(doors);

    QLabel* type = new QLabel(QString::fromStdString("SUV ONLY:"));
    type->setObjectName("type");
    details->addWidget(type);

    QLabel* traction = new QLabel("traction : "+ QString::fromStdString(sv.getTraction() ? "4x4" : "/"));
    traction->setObjectName("traction");
    traction->setWordWrap(true);
    details->addWidget(traction);

    QLabel* wheels = new QLabel("wheels : "+ QString::number(sv.getWheels()));
    wheels->setObjectName("wheels");
    wheels->setWordWrap(true);
    details->addWidget(wheels);

    QLabel* recovery = new QLabel("recovery : "+QString::number(sv.getRecovery()));
    recovery->setObjectName("recovery");
    recovery->setWordWrap(true);
    details->addWidget(recovery);
}

void Full::visit(const products::Sedan& se) {
    widget = new QWidget();
    widget->setObjectName("full-sedan");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* id = new QLabel(QString::number(se.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);

    QLabel* name = new QLabel("name : "+QString::fromStdString(se.getBrand() +" "+se.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(se.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(300, 300, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* list_price = new QLabel("list price : "+QString::number(se.getList_price()));
    list_price->setObjectName("list price");
    list_price->setWordWrap(true);
    details->addWidget(list_price);

    QLabel* horsepower = new QLabel("horsepower : "+QString::number(se.getHorses()));
    horsepower->setObjectName("horsepower");
    horsepower->setWordWrap(true);
    details->addWidget(horsepower);

    QLabel* kilo = new QLabel("kilometers : "+QString::number(se.getKilo()));
    kilo->setObjectName("kilometers");
    kilo->setWordWrap(true);
    details->addWidget(kilo);

    QLabel* doors = new QLabel("doors : "+QString::fromStdString(se.getDoors() ? "4" : "2"));
    doors->setObjectName("doors");
    doors->setWordWrap(true);
    details->addWidget(doors);

    QLabel* type = new QLabel(QString::fromStdString("SEDAN ONLY:"));
    type->setObjectName("type");
    details->addWidget(type);

    QLabel* habitability = new QLabel("habitability : "+QString::number(se.getHabitability()));
    habitability->setObjectName("habitability");
    habitability->setWordWrap(true);
    details->addWidget(habitability);

    QLabel* trunk_capacity = new QLabel("trunk capacity : "+QString::number(se.getCapacity()));
    trunk_capacity->setObjectName("trunk_capacity");
    trunk_capacity->setWordWrap(true);
    details->addWidget(trunk_capacity);

    QLabel* assisted_b = new QLabel("assisted braking : "+QString::fromStdString(se.getAssisted_brakingn()? "YES" : "NO"));
    assisted_b->setObjectName("assisted_braking");
    assisted_b->setWordWrap(true);
    details->addWidget(assisted_b);
}

void Full::visit(const products::Super_car& sc) {
    widget = new QWidget();
    widget->setObjectName("full-supercar");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* id = new QLabel(QString::number(sc.getId()));
    id->setObjectName("id");
    vbox->addWidget(id);

    QLabel* name = new QLabel("name : "+QString::fromStdString(sc.getBrand() +" "+sc.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(sc.getImage().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(300, 300, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* list_price = new QLabel("list price : "+QString::number(sc.getList_price()));
    list_price->setObjectName("list price");
    list_price->setWordWrap(true);
    details->addWidget(list_price);

    QLabel* horsepower = new QLabel("horsepower : "+QString::number(sc.getHorses()));
    horsepower->setObjectName("horsepower");
    horsepower->setWordWrap(true);
    details->addWidget(horsepower);

    QLabel* kilo = new QLabel("kilometers : "+QString::number(sc.getKilo()));
    kilo->setObjectName("kilometers");
    kilo->setWordWrap(true);
    details->addWidget(kilo);

    QLabel* doors = new QLabel("doors : "+QString::fromStdString(sc.getDoors() ? "4" : "2"));
    doors->setObjectName("doors");
    doors->setWordWrap(true);
    details->addWidget(doors);

    QLabel* type = new QLabel(QString::fromStdString("SUPER CAR ONLY:"));
    type->setObjectName("type");
    details->addWidget(type);

    QLabel* dMode = new QLabel("driving modes : "+QString::number(sc.getDrivingM()));
    dMode->setObjectName("driving_modes");
    dMode->setWordWrap(true);
    details->addWidget(dMode);

    QLabel* acc = new QLabel("acceleration : "+QString::number(sc.getAcceleration()));
    acc->setObjectName("acceleration");
    acc->setWordWrap(true);
    details->addWidget(acc);

    QLabel* aerodynamics = new QLabel("aerodynamic : "+QString::number(sc.getAerodynamics()));
    aerodynamics->setObjectName("aerodynamic");
    aerodynamics->setWordWrap(true);
    details->addWidget(aerodynamics);
}

QWidget* Full::getWidget() const {
    return widget;
}

QPushButton* Full::getViewButton() const {
    return view_button;
}

QPushButton* Full::getEditButton() const {
    return edit_button;
}

QPushButton* Full::getDeleteButton() const {
    return delete_button;
};

}
}
