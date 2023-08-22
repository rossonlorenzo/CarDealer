#include "typeselector.h"

#include "../products/constvisitor.h"

namespace View {

TypeSelector::TypeSelector(QComboBox* combo_box)
    : combo_box(combo_box)
{
}

void TypeSelector::visit(const products::Sedan& se) {
    (void) se;
    combo_box->setCurrentText("sedan");
}

void TypeSelector::visit(const products::Super_car& sc) {
    (void) sc;
    combo_box->setCurrentText("super car");
}

void TypeSelector::visit(const products::Suv& sv) {
    (void) sv;
    combo_box->setCurrentText("suv");
}

QComboBox* TypeSelector::getComboBox() {
    return combo_box;
}

TypeSelector& TypeSelector::setComboBox(QComboBox* combo_box) {
    this->combo_box = combo_box;
    return *this;
}

}
