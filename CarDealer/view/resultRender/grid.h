#ifndef GRID_H
#define GRID_H

#include "resultrenderstrategy.h"

#include "../resultwidget.h"
#include "../productRender/card.h"

namespace View {
namespace ResultRender {

class Grid: public ResultRenderStrategy {
  private:
    ProductRender::Card card;

  public:
    virtual void render(QGridLayout* grid,  products::List<const products::Car*>& products, QVector<WidgetLookup>* lookup);
};

}
}

#endif
