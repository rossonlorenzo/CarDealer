#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>
#include "../constvisitor.h"
#include "../suv.h"
#include "../sedan.h"
#include "../supercar.h"


namespace products {
namespace JsonConverter {

class JsonVisitor: public ConstVisitor {
  private:
    QJsonObject object;

  public:
    QJsonObject getObject() const;
    void visit(const Suv& sv);
    void visit(const Sedan& se);
    void visit(const Super_car& sc);
};

}
}

#endif // JSONVISITOR_H
