#ifndef LISTPRODUCTS_H
#define LISTPRODUCTS_H

#include "productrenderer.h"

#include "../resultwidget.h"

namespace View {
namespace ProductRender {

class ListProducts : public PRenderer {
  private:
    bool has_controls;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    ListProducts();
    virtual void visit(const products::Suv& sv);
    virtual void visit(const products::Sedan& se);
    virtual void visit(const products::Super_car& sc);
    bool hasControls() const;
    void setHasControls(const bool has_controls);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;
};

}
}

#endif
