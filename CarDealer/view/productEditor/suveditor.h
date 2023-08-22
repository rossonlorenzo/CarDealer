#ifndef SUVEDITOR_H
#define SUVEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

#include "careditor.h"

namespace View {
namespace PEditor {

class suvEditor: public CarEditor {
  private:
    QCheckBox* traction_input;
    QSpinBox* wheels_input;
    QSpinBox* recovery_input;

  public:
    suvEditor(QWidget* parent = 0);
    virtual ~suvEditor();
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

    void setValues(const products::Suv& sv);
};

}
}

#endif
