#ifndef PRODUCTINJECTOR_H
#define PRODUCTINJECTOR_H


#include "../../products/constvisitor.h"
#include "sedaneditor.h"
#include "supercareditor.h"
#include "suveditor.h"

namespace View {
namespace PEditor {

class PInjector: public products::ConstVisitor {
  private:
    sedanEditor& sedan_editor;
    superCarEditor& super_car_editor;
    suvEditor& suv_editor;

  public:
    PInjector(
            sedanEditor& sedan_editor,
            superCarEditor& super_car_editor,
            suvEditor& suv_editor
    );
    virtual void visit(const products::Sedan& se);
    virtual void visit(const products::Super_car& sc);
    virtual void visit(const products::Suv& sv);
};

}
}

#endif
