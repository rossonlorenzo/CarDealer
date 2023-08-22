#include "resultwidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "resultRender/listview.h"
#include "../products/car.h"
#include "../products/sedan.h"
#include "../products/supercar.h"
#include "../products/suv.h"

namespace View {

ResultsWidget::ResultsWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    results_total = new QLabel();
    hbox->addWidget(results_total);

    hbox->addStretch();
    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);

    renderer = new ResultRender::ListView();
    // Connects signals
}

void ResultsWidget::showAll(products::List<const products::Car*>& items, std::string type) {
    results_total->setText("Showing all data");
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }
    if(type!=""){
        products::List<const products::Car*>* filtered_products = new products::List<const products::Car*>();
    //  not the problem
        for (
            products::List<const products::Car*>::const_Iterator it=items.begin(); it!=items.end();
            it++
        ){
          if(type =="sedan"){
              if(dynamic_cast<products::Sedan*>(const_cast<products::Car*>(*it)))
                  filtered_products->add(*it);
          }else if(type =="super car"){
              if(dynamic_cast<products::Super_car*>(const_cast<products::Car*>(*it)))
                  filtered_products->add(*it);
          }else if(type =="suv"){
              if(dynamic_cast<products::Suv*>(const_cast<products::Car*>(*it)))
                  filtered_products->add(*it);
          }
        }
        renderer->render(grid, *filtered_products, &lookup);
        if(filtered_products->empty()){
            results_total->setText("No results for type: \"" + QString::fromStdString(type));
        }
    }else{
        renderer->render(grid, items, &lookup);
    }
    // Connects signals
    for (
        QVector<WidgetLookup>::iterator it = lookup.begin();
        it != lookup.end();
        it++
    ) {
        if (it->getViewButton()) {
            connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showItem, this, it->getProduct()));
        }
        if (it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getProduct()));
        }
        if (it->getDeleteButton()) {
            connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getProduct()));
        }
    }
}

void ResultsWidget::showResults(unsigned int query, products::List<const products::Car*>& items) {
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }
    const products::Car* item = items.getItemfromId(query);
    if (item != NULL) {
        results_total->setText("results for id \"" + QString::number(query) + "\":");
        products::List<const products::Car*>* list = new products::List<const products::Car*>();
        list->add(item);
        renderer->render(grid, *list, &lookup);
    }
    else {
        results_total->setText("No results for \"" + QString::number(query) + "\":");
    }


    // Connects signals
    for (
        QVector<WidgetLookup>::iterator it = lookup.begin();
        it != lookup.end();
        it++
    ) {
        if (it->getViewButton()) {
            connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showItem, this, it->getProduct()));
        }
        if (it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getProduct()));
        }
        if (it->getDeleteButton()) {
            connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getProduct()));
        }
    }
}
}
