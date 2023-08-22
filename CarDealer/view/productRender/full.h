#ifndef FULL_H
#define FULL_H

#include "productrenderer.h"
#include "listproducts.h"

#include "../resultwidget.h"

namespace View {
namespace ProductRender {

class Full: public PRenderer {
  private:
    ListProducts list_products;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    virtual void visit(const products::Suv& sv);
    virtual void visit(const products::Sedan& se);
    virtual void visit(const products::Super_car& sc);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;
};

}
}

#endif // FULL_H
