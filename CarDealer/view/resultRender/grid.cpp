#include "grid.h"

namespace View {
namespace ResultRender {

void Grid::render(QGridLayout* grid, products::List<const products::Car*>& products, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    unsigned int row_size = 100;
    for (
        products::List<const products::Car*>::const_Iterator it=products.begin(); it!=products.end();
        it++
    ) {
        (*it)->accept(card);
        QWidget* widget = card.getWidget();
        grid->addWidget(widget, index / row_size, index % row_size);
        lookup->push_back(WidgetLookup(
            *it,
            widget,
            card.getViewButton(),
            card.getEditButton(),
            card.getDeleteButton()
        ));
        index++;
    }
}

}
}
