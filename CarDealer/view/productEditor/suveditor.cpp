#include "suveditor.h"

#include <QFormLayout>

#include "../../products/suv.h"

namespace View {
namespace PEditor {

suvEditor::suvEditor(QWidget* parent)
    : CarEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("suv-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);


    traction_input = new QCheckBox();
    traction_input->setObjectName("traction_input");
    traction_input->setChecked(false);
    form->addRow("traction :", traction_input);

    wheels_input = new QSpinBox();
    wheels_input->setObjectName("wheels_input");
    wheels_input->setMinimum(0);
    wheels_input->setMaximum(22);
    form->addRow("wheels :", wheels_input);

    recovery_input = new QSpinBox();
    recovery_input->setObjectName("recovery_input");
    recovery_input->setMinimum(0);
    recovery_input->setMaximum(5);
    form->addRow("recovery :", recovery_input);

}

suvEditor::~suvEditor() {
}

products::Car* suvEditor::create(
        const unsigned int id,
        const QString& name,
        const QString& brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const QString& image_path
) const {
    return new products::Suv(
        id,
        name.toStdString(),
        brand.toStdString(),
        list_price,
        horsepower,
        kilometers,
        doors,
        image_path.toStdString(),
        traction_input->isChecked(),
        wheels_input->value(),
        recovery_input->value()
        );
   }

   void suvEditor::setValues(const products::Suv& sv) {
        traction_input->setChecked(sv.getTraction());
        wheels_input->setValue(sv.getWheels());
        recovery_input->setValue(sv.getRecovery());
   }

}
}
