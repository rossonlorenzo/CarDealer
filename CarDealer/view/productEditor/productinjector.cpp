#include "productinjector.h"

namespace View {
namespace PEditor {

PInjector::PInjector (
    sedanEditor& sedan_editor,
    superCarEditor& super_car_editor,
    suvEditor& suv_editor
)
    : sedan_editor(sedan_editor), super_car_editor(super_car_editor),
    suv_editor(suv_editor)
{
}

void PInjector::visit(const products::Sedan& se) {
    sedan_editor.setValues(se);
}

void PInjector::visit(const products::Super_car& sc) {
    super_car_editor.setValues(sc);
}

void PInjector::visit(const products::Suv& sv) {
    suv_editor.setValues(sv);
}

}
}
