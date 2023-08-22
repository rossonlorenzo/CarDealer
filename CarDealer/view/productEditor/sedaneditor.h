#ifndef SEDANEDITOR_H
#define SEDANEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

#include "careditor.h"

namespace View {
namespace PEditor {

class sedanEditor: public CarEditor {
  private:
    QSpinBox* habitability_input;
    QSpinBox* trunk_capacity_input;
    QCheckBox* assisted_braking_input;

  public:
    sedanEditor(QWidget* parent = 0);
    virtual ~sedanEditor();
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

    void setValues(const products::Sedan& se);
};

}
}

#endif
