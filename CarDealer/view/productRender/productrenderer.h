#ifndef PRENDERER_H
#define PRENDERER_H

#include <QWidget>
#include <QPushButton>

#include "../../products/car.h"
#include "../../products/constvisitor.h"

namespace View {
namespace ProductRender {

class PRenderer: public products::ConstVisitor {
  public:
    virtual QWidget* getWidget() const = 0;
    virtual QPushButton* getViewButton() const = 0;
    virtual QPushButton* getEditButton() const = 0;
    virtual QPushButton* getDeleteButton() const = 0;
};

}
}

#endif
