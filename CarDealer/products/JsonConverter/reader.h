#ifndef READER_H
#define READER_H


#include <map>
#include <QJsonObject>

#include "PReader.h"

namespace products {
namespace JsonConverter {

class Reader: public PReader {
  private:
    std::map<unsigned int, const Car*> cache;

  public:
    const std::map<unsigned int, const Car*>& getCache() const;
    Reader& clear();
    virtual const Car* read(const QJsonObject& object);

  private:
    const Car* readSuv(const QJsonObject& object) const;
    const Car* readSedan(const QJsonObject& object) const;
    const Car* readSuper_car(const QJsonObject& object) const;
};

}
}
#endif // READER_H
