#include "listview.h"
#include "../../products/linkedlist.h"

namespace View {
namespace ResultRender {

void ListView::render(QGridLayout* grid, products::List<const products::Car*>& products, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    for(products::List<const products::Car*>::const_Iterator it=products.begin(); it!=products.end(); it++){
        (*it)->accept(list_products);
        QWidget* widget = list_products.getWidget();
        grid->addWidget(widget, index, 0);
        lookup->push_back(WidgetLookup(
            *it,
            widget,
            list_products.getViewButton(),
            list_products.getEditButton(),
            list_products.getDeleteButton()
        ));
        index++;
    }
}

}
}
