#include "json.h"
#include "jsonvisitor.h"
#include "../suv.h"

namespace products {
namespace JsonConverter {

Json::Json(PReader& reader)
    : reader(reader)
{
}

const PReader& Json::getReader() const {
    return reader;
}

QJsonObject Json::fromObject(const Car& item) const {
    JsonVisitor json_visitor;
    item.accept(json_visitor);
    return json_visitor.getObject();
}

const Car* Json::toObject(const QJsonObject& json) const {
    return reader.read(json);
}

}
}
