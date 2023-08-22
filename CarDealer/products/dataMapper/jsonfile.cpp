#include "jsonfile.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "../JsonConverter/reader.h"

namespace products {
namespace DataMapper {

JsonFile::JsonFile(const std::string& path, JsonConverter::Json& converter)
    : path(path), converter(converter)
{
}

const std::string& JsonFile::getPath() const {
    return path;
}

JsonFile& JsonFile::setPath(const std::string& path) {
    this->path = path;
    return *this;
}

const JsonConverter::Json& JsonFile::getConverter() const {
    return converter;
}

// @todo check errors
JsonFile& JsonFile::store(const List<const Car*>& items) {
    QJsonArray json_items;
    for (
        List<const Car*>::const_Iterator it = items.begin();
        it != items.end();
        it++
    ) {
        json_items.push_back(converter.fromObject(**it));
    }
    QJsonDocument document(json_items);
    QFile json_file(path.c_str());
    json_file.open(QFile::WriteOnly);
    json_file.write(document.toJson());
    json_file.close();
    return *this;
}

// @todo check errors
List<const Car*>& JsonFile::load() {
    List<const Car*>* products = new List<const Car*>();
    QFile json_file(path.c_str());
    json_file.open(QFile::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_items = document.array();

    for (const QJsonValue& value: json_items) {
        QJsonObject json_object = value.toObject();
        products->add(converter.toObject(json_object));
    }
    return *products;
}

}
}
