#ifndef VIEW_WIDGET_LOOKUP_H
#define VIEW_WIDGET_LOOKUP_H

#include <QWidget>
#include <QPushButton>

#include "../products/car.h"

namespace View {

class WidgetLookup {
  private:
    const products::Car* product;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    WidgetLookup(
        const products::Car* product,
        QWidget* widget,
        QPushButton* view_button,
        QPushButton* edit_button,
        QPushButton* delete_button
    );
     const products::Car* getProduct() const;
    QWidget* getWidget() const;
    QPushButton* getViewButton() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
};

}

#endif
