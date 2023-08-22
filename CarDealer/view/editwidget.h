#ifndef EDIT_WIDGET_H
#define EDIT_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <QStackedLayout>

#include "MainWindow.h"
#include "../products/car.h"
#include "productEditor/careditor.h"
//#include "../Item/Repository/JsonRepository.h"
#include "products/linkedlist.h"


namespace View {

class EditWidget: public QWidget {
    Q_OBJECT
  private:
    MainWindow* main_window;
    products::List<const products::Car*>* items;
    const products::Car* subject;

    QLabel* status;
    QSpinBox* id_input;
    QLineEdit* name_input;
    QLineEdit* brand_input;
    QSpinBox* list_price_input;
    QSpinBox* horsepower_input;
    QSpinBox* kilometers_input;
    QCheckBox* doors_input;
    QLineEdit* image_path_input;
    QStackedLayout* stacked_editor;
    QVector<PEditor::CarEditor*> editors;

  public:
    EditWidget(
      MainWindow* main_window,
      products::List<const products::Car*>* items,
      const products::Car* subject
    );

  public slots:
    void selectImage();
    void showType(int index);
    void apply();
};

}

#endif
