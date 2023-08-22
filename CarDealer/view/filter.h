#ifndef FILTER_H
#define FILTER_H


#include <QComboBox>

#include "../products/constvisitor.h"

namespace View {

class Filter {
  private:
    QComboBox* combo_box;

  public:
    Filter(QComboBox* combo_box);
    void filter(const std::string& type);
    QComboBox* getComboBox();
    Filter& setComboBox(QComboBox* combo_box);
};

}

#endif
