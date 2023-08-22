#include "widgetlookup.h"

namespace View {

WidgetLookup::WidgetLookup(
    const products::Car* product,
    QWidget* widget,
    QPushButton* view_button,
    QPushButton* edit_button,
    QPushButton* delete_button
)
    : product(product), widget(widget), view_button(view_button), edit_button(edit_button), delete_button(delete_button)
{
}

const products::Car* WidgetLookup::getProduct() const {
    return product;
}

QWidget* WidgetLookup::getWidget() const {
    return widget;
}

QPushButton* WidgetLookup::getViewButton() const {
    return view_button;
}

QPushButton* WidgetLookup::getEditButton() const {
    return edit_button;
}

QPushButton* WidgetLookup::getDeleteButton() const {
    return delete_button;
}

}
