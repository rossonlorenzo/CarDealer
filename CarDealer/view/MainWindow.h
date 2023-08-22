#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "products/car.h"
#include "products/linkedlist.h"
#include "products/dataMapper/jsonfile.h"
#include "resultwidget.h"
#include "productRender/full.h"
#include "searchwidget.h"



namespace View {

class MainWindow: public QMainWindow {
    Q_OBJECT
  private:
    bool has_unsaved_changes;
    QAction* create_item;
    QAction* reload_item;
    QToolBar* toolbar;
    products::DataMapper::JsonFile& jfile;
    products::List<const products::Car*>& products;
    QStackedWidget* stacked_widget;
    ResultsWidget* results_widget;
    ProductRender::Full full_renderer;
    SearchWidget* search_widget;


  public:
    explicit MainWindow(products::DataMapper::JsonFile& jfile, products::List<const products::Car*>& products, QWidget *parent = 0);
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();

  private:
    void clearStack();

  public slots:
    void newDataset();
    void openDataset();
    void saveDataset();
    void toggleToolbar();
    void showStatus(QString message);
    void deploy();
    void filter(std::string type);
    void search(unsigned int query);
    void createItem();
    void showItem(const products::Car* item);
    void editItem(const products::Car* item);
    void deleteItem(const products::Car* item);
    void close();
};

}

#endif
