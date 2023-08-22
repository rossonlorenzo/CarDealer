#ifndef TYPESELECTOR_H
#define TYPESELECTOR_H

#include <QComboBox>

#include "../products/constvisitor.h"

namespace View {

class TypeSelector: public products::ConstVisitor {
  private:
    QComboBox* combo_box;

  public:
    TypeSelector(QComboBox* combo_box);
    virtual void visit(const products::Sedan& se);
    virtual void visit(const products::Super_car& sc);
    virtual void visit(const products::Suv& sv);
    QComboBox* getComboBox();
    TypeSelector& setComboBox(QComboBox* combo_box);
};

}

#endif
