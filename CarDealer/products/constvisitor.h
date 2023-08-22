#ifndef CONSTVISITOR_H
#define CONSTVISITOR_H

namespace products {

class Suv;
class Sedan;
class Super_car;

class ConstVisitor {
  public:
    virtual ~ConstVisitor() {};
    virtual void visit(const Suv& sv) = 0;
    virtual void visit(const Sedan& se) = 0;
    virtual void visit(const Super_car& sc) = 0;
};

}

#endif // CONSTVISITOR_H
