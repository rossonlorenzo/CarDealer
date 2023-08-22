#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QVector>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "products/dataMapper/jsonfile.h"
#include "view/resultRender/resultrenderstrategy.h"
#include "widgetlookup.h"

namespace View {

class ResultsWidget: public QWidget {
    Q_OBJECT
  private:
    QLabel* results_total;
    QVector<WidgetLookup> lookup;
    QGridLayout* grid;
    ResultRender::ResultRenderStrategy* renderer;

  public:
    explicit ResultsWidget(QWidget* parent = 0);

  signals:
    void refreshResults();
    void showItem(const products::Car* item);
    void editItem(const products::Car* item);
    void deleteItem(const products::Car* item);

  public slots:
    void showAll(products::List<const products::Car*>& items, std::string type);
    void showResults(unsigned int query, products::List<const products::Car*>& items);
};

}

#endif
