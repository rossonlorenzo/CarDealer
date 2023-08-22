#include "reader.h"

#include <stdexcept>
#include <QJsonArray>

#include "../suv.h"
#include "../sedan.h"
#include "../supercar.h"


namespace products {
namespace JsonConverter {

const std::map<unsigned int, const Car*>& Reader::getCache() const {
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

const Car* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("type");
    if (type.isUndefined()) {
        throw std::invalid_argument("Missing item type.");
    }
    const unsigned int identifier = object.value("id").toInt();
    if (cache.count(identifier) > 0) {
        return cache[identifier];
    }
    else if (type.toString().compare("Suv") == 0) {
        cache[identifier] = readSuv(object);
    }
    else if (type.toString().compare("Sedan") == 0) {
        cache[identifier] = readSedan(object);
    }
    else if (type.toString().compare("Super_car") == 0) {
        cache[identifier] = readSuper_car(object);
    }
    else {
        throw std::invalid_argument("Unknown type.");
    }
    return cache[identifier];
}

const Car* Reader::readSuv(const QJsonObject& object) const {
    return new Suv(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("brand").toString().toStdString(),
        object.value("list_price").toInt(),
        object.value("horsepower").toInt(),
        object.value("kilometers").toInt(),
        object.value("doors").toBool(),
        object.value("imagePath").toString().toStdString(),
        object.value("traction").toBool(),
        object.value("wheels").toInt(),
        object.value("recovery").toInt()
    );
}

const Car* Reader::readSedan(const QJsonObject &object) const {
    return new Sedan(
         object.value("id").toInt(),
         object.value("name").toString().toStdString(),
         object.value("brand").toString().toStdString(),
         object.value("list_price").toInt(),
         object.value("horsepower").toInt(),
         object.value("kilometers").toInt(),
         object.value("doors").toBool(),
         object.value("imagePath").toString().toStdString(),
         object.value("habitability").toInt(),
         object.value("trunk_capacity").toInt(),
         object.value("assisted_braking").toBool()
    );
}

const Car* Reader::readSuper_car(const QJsonObject& object) const {
    return new Super_car(
          object.value("id").toInt(),
          object.value("name").toString().toStdString(),
          object.value("brand").toString().toStdString(),
          object.value("list_price").toInt(),
          object.value("horsepower").toInt(),
          object.value("kilometers").toInt(),
          object.value("doors").toBool(),
          object.value("imagePath").toString().toStdString(),
          object.value("driving_modes").toInt(),
          object.value("aerodynamics").toInt(),
          object.value("acceleration").toInt()
    );
}

}
}
