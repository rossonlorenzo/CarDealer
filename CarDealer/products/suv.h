#ifndef SUV_H
#define SUV_H
#include <iostream>
#include "car.h"
#include "constvisitor.h"

namespace products {

class Suv : public Car{
    private:
           bool traction;
           unsigned int wheels;
           unsigned int recovery;
    public:
    Suv(
        const unsigned int id,
        const std::string name,
        const std::string brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const std::string image_path,
        const bool traction,
        const unsigned int wheels,
        const unsigned int recovery
        );
    bool getTraction() const;
    unsigned int getWheels() const;
    unsigned int getRecovery() const;

    Suv& setTraction(const bool);
    Suv& setWheels(const unsigned int);
    Suv& setRecovery(const unsigned int);

    virtual char evaluetion() const;
    virtual unsigned int finalPrice() const;
    virtual void accept(ConstVisitor& visitor) const;
    // virtual void print(std::ostream&, const Car&);
    // std::ostream& printSuv(std::ostream&, const Suv&);
    //correggere stream
};

}

#endif
// Suv
// 	Trazione (4x4 o no)
// 	Cerchi (misura)
// 	Ripresa
