#ifndef CAR_EDITOR_H
#define CAR_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../products/car.h"

namespace View {
namespace PEditor {

class CarEditor: public QWidget {
    Q_OBJECT
  public:
    CarEditor(QWidget* parent = 0);
    virtual ~CarEditor();
    virtual products::Car* create(
        const unsigned int id,
        const QString& name,
        const QString& brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const QString& image_path

    ) const = 0;
};

}
}

#endif
