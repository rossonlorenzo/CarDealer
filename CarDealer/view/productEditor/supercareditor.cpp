#include "supercareditor.h"

#include <QFormLayout>

#include "../../products/supercar.h"

namespace View {
namespace PEditor {

superCarEditor::superCarEditor(QWidget* parent)
    : CarEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("super_car-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

    driving_modes_input = new QSpinBox();
    driving_modes_input->setObjectName("driving_modes_input");
    driving_modes_input->setMinimum(0);
    driving_modes_input->setMaximum(5);
    form->addRow("driving modes :", driving_modes_input);

    aerodynamics_input = new QSpinBox();
    aerodynamics_input->setObjectName("aerodynamics_input");
    aerodynamics_input->setMinimum(0);
    aerodynamics_input->setMaximum(5);
    form->addRow("aerodynamics :", aerodynamics_input);

    acceleration_input = new QSpinBox();
    acceleration_input->setObjectName("acceleration_input");
    acceleration_input->setMinimum(0);
    acceleration_input->setMaximum(3);
    form->addRow("acceleration :", acceleration_input);

}

superCarEditor::~superCarEditor() {
}

products::Car* superCarEditor::create(
        const unsigned int id,
        const QString& name,
        const QString& brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const QString& image_path
) const {
    return new products::Super_car(
        id,
        name.toStdString(),
        brand.toStdString(),
        list_price,
        horsepower,
        kilometers,
        doors,
        image_path.toStdString(),
        driving_modes_input->value(),
        aerodynamics_input->value(),
        acceleration_input->value()
    );
}

void superCarEditor::setValues(const products::Super_car& sc) {
    driving_modes_input->setValue(sc.getDrivingM());
    aerodynamics_input->setValue(sc.getAerodynamics());
    acceleration_input->setValue(sc.getAcceleration());
}

}
}
