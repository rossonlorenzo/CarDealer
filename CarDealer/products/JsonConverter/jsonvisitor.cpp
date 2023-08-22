#include "jsonvisitor.h"

#include <QJsonArray>

namespace products {
namespace JsonConverter {

QJsonObject JsonVisitor::getObject() const {
    return object;
}

void JsonVisitor::visit(const Suv& sv) {
    QJsonObject Suv_object;
    Suv_object.insert("type", QJsonValue::fromVariant("Suv"));
    Suv_object.insert("id", QJsonValue::fromVariant(sv.getId()));
    Suv_object.insert("name", QJsonValue::fromVariant(sv.getName().c_str()));
    Suv_object.insert("brand", QJsonValue::fromVariant(sv.getBrand().c_str()));
    Suv_object.insert("list_price", QJsonValue::fromVariant(sv.getList_price()));
    Suv_object.insert("horsepower", QJsonValue::fromVariant(sv.getHorses()));
    Suv_object.insert("kilometers", QJsonValue::fromVariant(sv.getKilo()));
    Suv_object.insert("doors", QJsonValue::fromVariant(sv.getDoors()));
    Suv_object.insert("imagePath", QJsonValue::fromVariant(sv.getImage().c_str()));
    Suv_object.insert("traction", QJsonValue::fromVariant(sv.getTraction()));
    Suv_object.insert("wheels", QJsonValue::fromVariant(sv.getWheels()));
    Suv_object.insert("recovery", QJsonValue::fromVariant(sv.getRecovery()));
    object = Suv_object;
}

void JsonVisitor::visit(const Sedan& se) {
    QJsonObject Sedan_object;
    Sedan_object.insert("type", QJsonValue::fromVariant("Sedan"));
    Sedan_object.insert("id", QJsonValue::fromVariant(se.getId()));
    Sedan_object.insert("name", QJsonValue::fromVariant(se.getName().c_str()));
    Sedan_object.insert("brand", QJsonValue::fromVariant(se.getBrand().c_str()));
    Sedan_object.insert("list_price", QJsonValue::fromVariant(se.getList_price()));
    Sedan_object.insert("horsepower", QJsonValue::fromVariant(se.getHorses()));
    Sedan_object.insert("kilometers", QJsonValue::fromVariant(se.getKilo()));
    Sedan_object.insert("doors", QJsonValue::fromVariant(se.getDoors()));
    Sedan_object.insert("imagePath", QJsonValue::fromVariant(se.getImage().c_str()));
    Sedan_object.insert("habitability", QJsonValue::fromVariant(se.getHabitability()));
    Sedan_object.insert("trunk_capacity", QJsonValue::fromVariant(se.getCapacity()));
    Sedan_object.insert("assisted_braking", QJsonValue::fromVariant(se.getAssisted_brakingn()));
    object = Sedan_object;
}

void JsonVisitor::visit(const Super_car& sc) {
    QJsonObject Super_car_object;
    Super_car_object.insert("type", QJsonValue::fromVariant("Super_car"));
    Super_car_object.insert("id", QJsonValue::fromVariant(sc.getId()));
    Super_car_object.insert("name", QJsonValue::fromVariant(sc.getName().c_str()));
    Super_car_object.insert("brand", QJsonValue::fromVariant(sc.getBrand().c_str()));
    Super_car_object.insert("list_price", QJsonValue::fromVariant(sc.getList_price()));
    Super_car_object.insert("horsepower", QJsonValue::fromVariant(sc.getHorses()));
    Super_car_object.insert("kilometers", QJsonValue::fromVariant(sc.getKilo()));
    Super_car_object.insert("doors", QJsonValue::fromVariant(sc.getDoors()));
    Super_car_object.insert("imagePath", QJsonValue::fromVariant(sc.getImage().c_str()));
    Super_car_object.insert("driving_modes", QJsonValue::fromVariant(sc.getDrivingM()));
    Super_car_object.insert("aerodynamics", QJsonValue::fromVariant(sc.getAerodynamics()));
    Super_car_object.insert("acceleration", QJsonValue::fromVariant(sc.getAcceleration()));
    object = Super_car_object;
}

}
}
