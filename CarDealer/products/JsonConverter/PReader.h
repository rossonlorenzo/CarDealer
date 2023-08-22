#ifndef PREADER_H
#define PREADER_H

#include <QJsonObject>

#include "../car.h"

namespace products {
namespace JsonConverter {

class PReader {
  public:
    virtual ~PReader() {};
    virtual const Car* read(const QJsonObject& object) = 0;
};

}
}

#endif
