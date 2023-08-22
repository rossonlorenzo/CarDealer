#ifndef LISTVIEW_H
#define LISTVIEW_H


#include "resultrenderstrategy.h"

#include <QGridLayout>

#include "resultrenderstrategy.h"

#include "../resultwidget.h"
#include "../productRender/productrenderer.h"
#include "../productRender/listproducts.h"

namespace View {
namespace ResultRender {

class ListView : public ResultRenderStrategy{
  private:
    ProductRender::ListProducts list_products ;

  public:
     virtual void render(QGridLayout* grid,  products::List<const products::Car*>& products, QVector<WidgetLookup>* lookup);
};

}
}

#endif
