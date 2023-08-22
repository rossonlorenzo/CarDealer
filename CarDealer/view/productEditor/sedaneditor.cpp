#include "sedaneditor.h"

#include <QFormLayout>

#include "../../products/sedan.h"

namespace View {
namespace PEditor {

sedanEditor::sedanEditor(QWidget* parent)
    : CarEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("sedan-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

    habitability_input = new QSpinBox();
    habitability_input->setObjectName("habitability_input");
    habitability_input->setMinimum(0);
    habitability_input->setMaximum(5);
    form->addRow("habitability :", habitability_input);

    trunk_capacity_input = new QSpinBox();
    trunk_capacity_input->setObjectName("trunk_capacity_input");
    trunk_capacity_input->setMinimum(0);
    trunk_capacity_input->setMaximum(3);
    form->addRow("trunk capacity :", trunk_capacity_input);

    assisted_braking_input = new QCheckBox();
    assisted_braking_input->setObjectName("assisted_braking_input");
    assisted_braking_input->setChecked(false);
    form->addRow("assisted braking :", assisted_braking_input);
}

sedanEditor::~sedanEditor() {
}

products::Car* sedanEditor::create(
        const unsigned int id,
        const QString& name,
        const QString& brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const QString& image_path
) const {
    return new products::Sedan(
        id,
        name.toStdString(),
        brand.toStdString(),
        list_price,
        horsepower,
        kilometers,
        doors,
        image_path.toStdString(),
        habitability_input->value(),
        trunk_capacity_input->value(),
        assisted_braking_input->isChecked()
    );
}

void sedanEditor::setValues(const products::Sedan& se) {
    habitability_input->setValue(se.getHabitability());
    trunk_capacity_input->setValue(se.getCapacity());
    assisted_braking_input->setChecked(se.getAssisted_brakingn());
}

}
}
