#include "filter.h"

#include "../products/constvisitor.h"

namespace View {

Filter::Filter(QComboBox* combo_box)
    : combo_box(combo_box)
{
}

void Filter::filter(const std::string& type) {
    if(type == "sedan"){

    }
}

QComboBox* Filter::getComboBox() {
    return combo_box;
}

Filter& Filter::setComboBox(QComboBox* combo_box) {
    this->combo_box = combo_box;
    return *this;
}

}

