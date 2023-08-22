#ifndef RESULTRENDERSTRATEGY_H
#define RESULTRENDERSTRATEGY_H

#include <QGridLayout>

#include "../../products/linkedlist.h"
#include "../widgetlookup.h"

namespace View {
namespace ResultRender {

class ResultRenderStrategy {
  public:
    virtual ~ResultRenderStrategy() = default;
    virtual void render(QGridLayout* grid,  products::List<const products::Car*>& products, QVector<WidgetLookup>* lookup) = 0;
};

}
}

#endif
