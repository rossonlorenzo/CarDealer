#ifndef JSON_H
#define JSON_H

#include <QJsonObject>
#include "../car.h"
#include "PReader.h"

namespace products {
namespace JsonConverter {

class Json {
  private:
    PReader& reader;

  public:
    Json(PReader& reader);
    const PReader& getReader() const;
    QJsonObject fromObject(const Car& item) const;
    const Car* toObject(const QJsonObject& json) const;
};

}
}

#endif
