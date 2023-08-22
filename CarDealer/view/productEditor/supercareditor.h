#ifndef SUPERCAREDITOR_H
#define SUPERCAREDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>

#include "careditor.h"

namespace View {
namespace PEditor {

class superCarEditor: public CarEditor {
  private:
    QSpinBox* driving_modes_input;
    QSpinBox* aerodynamics_input;
    QSpinBox* acceleration_input;

  public:
    superCarEditor(QWidget* parent = 0);
    virtual ~superCarEditor();
    virtual products::Car* create(
            const unsigned int id,
            const QString& name,
            const QString& brand,
            const unsigned int list_price,
            const unsigned int horsepower,
            const unsigned int kilometers,
            const bool doors,
            const QString& image_path
    ) const;

    void setValues(const products::Super_car& sc);
};

}
}

#endif
