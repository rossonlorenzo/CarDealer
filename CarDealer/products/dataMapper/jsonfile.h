#ifndef JSON_FILE_H
#define JSON_FILE_H

#include <string>

#include "../car.h"
#include "../JsonConverter/json.h"
#include "../linkedlist.h"

namespace products {
namespace DataMapper {

class JsonFile {
  private:
    std::string path;
    JsonConverter::Json& converter;

  public:
    JsonFile(const std::string& path, JsonConverter::Json& converter);
    const std::string& getPath() const;
    JsonFile& setPath(const std::string& path);
    const JsonConverter::Json& getConverter() const;
    JsonFile& store(const List<const Car*>& products);
    List<const Car*>& load();
};

}
}

#endif
