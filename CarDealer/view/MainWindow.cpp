#include "MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QSplitter>
#include <QFileDialog>
#include <QStackedWidget>
#include <QScrollArea>

#include "editwidget.h"
#include "searchwidget.h"
#include "../products/dataMapper/jsonfile.h"
#include "../products/JsonConverter/reader.h"
#include "../products/JsonConverter/json.h"
#include "../products/linkedlist.h"
#include "../products/car.h"
#include "../products/sedan.h"
#include "../products/supercar.h"
#include "../products/suv.h"

namespace View {
// ATTENZIONE PROVA A RENDERE jfile un *
// e cambia open e new file
MainWindow::MainWindow(products::DataMapper::JsonFile& jfile, products::List<const products::Car*>& products, QWidget *parent)
    : QMainWindow(parent),
    has_unsaved_changes(false),
    jfile(jfile),
    products(products)
{
    // Actions
    QAction* create = new QAction(
        QIcon(QPixmap((":/assets/icons/new.svg"))),
        "New"
    );
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    QAction* open = new QAction(
        "Open"
    );
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* save = new QAction(
        "Save"
    );
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* close = new QAction(
        "Close"
    );
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    QAction* togge_toolbar = new QAction(
        "Toolbar"
    );
    create_item = new QAction(
        "New Item"
    );

    create_item->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_item->setEnabled(false);

    reload_item = new QAction(
        "Show All"
    );
    reload_item->setEnabled(false);
    // Sets menu bar
    QMenu* file = menuBar()->addMenu("&File");
    file->addAction(create);
    file->addAction(open);
    file->addAction(save);
    file->addSeparator();
    file->addAction(close);
    QMenu* item_menu = menuBar()->addMenu("&Item");
    item_menu->addAction(create_item);
    item_menu->addAction(reload_item);
    QMenu* view = menuBar()->addMenu("&View");
    view->addAction(togge_toolbar);

    // Sets toolbar
    toolbar = addToolBar("File Toolbar");
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addSeparator();
    toolbar->addAction(create_item);
    toolbar->addAction(reload_item);
    toolbar->addSeparator();
    toolbar->addAction(close);

    // Sets main panel
    QSplitter* splitter = new QSplitter(this);
    setCentralWidget(splitter);

    search_widget = new SearchWidget();
    splitter->addWidget(search_widget);

    stacked_widget = new QStackedWidget(this);
    splitter->addWidget(stacked_widget);

    results_widget = new ResultsWidget();
    stacked_widget->addWidget(results_widget);

    splitter->setSizes(QList<int>() << 1000 << 3000);

    // Connects signals
    connect(create, &QAction::triggered, this, &MainWindow::newDataset);
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
    connect(close, &QAction::triggered, this, &MainWindow::close);
    connect(togge_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);
    connect(results_widget, &ResultsWidget::showItem, this, &MainWindow::showItem);
    connect(create_item, &QAction::triggered, this, &MainWindow::createItem);
    connect(reload_item, &QAction::triggered, this, &MainWindow::deploy);
    connect(results_widget, &ResultsWidget::editItem, this, &MainWindow::editItem);
    connect(results_widget, &ResultsWidget::deleteItem, this, &MainWindow::deleteItem);
    connect(results_widget, &ResultsWidget::refreshResults, this, &MainWindow::deploy);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(search_widget, &SearchWidget::filter_event, this, &MainWindow::filter);

    // Status bar
    showStatus("Ready.");
}

MainWindow& MainWindow::reloadData() {
    //products = jfile.load();
    return *this;
}

SearchWidget* MainWindow::getSearchWidget() {
    return search_widget;
}

void MainWindow::clearStack() {
    QWidget* widget = stacked_widget->widget(1);
    while (widget) {
        stacked_widget->removeWidget(widget);
        delete widget;
        widget = stacked_widget->widget(1);
    }
}

void MainWindow::newDataset() {
    QString path = QFileDialog::getSaveFileName(
        this,
        "Creates new Dataset",
        "./",
        "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }
    dynamic_cast<products::JsonConverter::Reader&>(const_cast<products::JsonConverter::PReader&>(jfile.getConverter().getReader())).clear();
    jfile.setPath(path.toStdString());
    products = jfile.load();
    reloadData();
    deploy();
    create_item->setEnabled(true);
    reload_item->setEnabled(true);
    showStatus("New dataset created.");
}

void MainWindow::openDataset() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Open a Dataset",
        "./",
        "JSON files *.json"
    );
    if (path.isEmpty()) {
        return;
    }
    dynamic_cast<products::JsonConverter::Reader&>(const_cast<products::JsonConverter::PReader&>(jfile.getConverter().getReader())).clear();
    jfile.setPath(path.toStdString());
    products = jfile.load();
    reloadData();
    deploy();
    create_item->setEnabled(true);
    reload_item->setEnabled(true);
    showStatus("Data successfully loaded from " + path + ".");
}

void MainWindow::saveDataset() {
    if (jfile.getPath() == "") {
        return;
    }
    jfile.store(products);
    has_unsaved_changes = false;
    showStatus("Dataset saved.");
}


void MainWindow::toggleToolbar() {
    toolbar->setVisible(!toolbar->isVisible());
    showStatus("Toolbar toggled.");
}

void MainWindow::showStatus(QString message) {
    statusBar()->showMessage(message);
}

void MainWindow::deploy() {
      showStatus("Data loaded");
      results_widget->showAll(products, "");
      stacked_widget->setCurrentIndex(0);
      clearStack();
}

void MainWindow::filter(std::string type) {
      if(!products.empty()){
      showStatus("Applying filter");
      results_widget->showAll(products, type);
      }else{
      showStatus("No products loaded");
      }
      stacked_widget->setCurrentIndex(0);
      clearStack();
}

void MainWindow::search(unsigned int query) {
      if(!products.empty()){
      showStatus("Running query");
      results_widget->showResults(query, products);
      }else{
      showStatus("No products loaded");
      }
      stacked_widget->setCurrentIndex(0);
      clearStack();
}

void MainWindow::createItem() {
    clearStack();
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    EditWidget* edit_widget = new EditWidget(this, &products, nullptr);
    scroll_area->setWidget(edit_widget);
    stacked_widget->addWidget(scroll_area);
    stacked_widget->setCurrentIndex(1);
    has_unsaved_changes = true;
    showStatus("Creating a new item.");
}

void MainWindow::showItem(const products::Car* item) {
    clearStack();
    item->accept(full_renderer);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(full_renderer.getWidget());
    stacked_widget->addWidget(scroll_area);
    stacked_widget->setCurrentIndex(1);
    showStatus("Showing item " + QString::fromStdString(item->getName()) + ".");
}

void MainWindow::editItem(const products::Car* item) {
    clearStack();
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    EditWidget* edit_widget = new EditWidget(this, &products, item);
    scroll_area->setWidget(edit_widget);
    stacked_widget->addWidget(scroll_area);
    stacked_widget->setCurrentIndex(1);
    has_unsaved_changes = true;
    showStatus("Editing item " + QString::fromStdString(item->getName()) + ".");
}

void MainWindow::deleteItem(const products::Car* item) {
    showStatus("Item " + QString::fromStdString(item->getName()) + " removed.");
    products.remove(item);
    has_unsaved_changes = true;
    reloadData();
    deploy();
}

void MainWindow::close() {
    if (has_unsaved_changes) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
            this,
            "Quit?",
            "There are unsaved changes.\nDo you really want to quit?",
            QMessageBox::Yes | QMessageBox::No
        );
        if (confirmation == QMessageBox::Yes) {
            QApplication::quit();
        }
    }
    else {
        QApplication::quit();
    }
}

}
