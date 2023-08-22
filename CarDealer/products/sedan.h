#ifndef SEDAN_H
#define SEDAN_H
#include <iostream>
#include "car.h"
#include "constvisitor.h"

namespace products {

class Sedan : public Car{
    private:
           unsigned int habitability;
           unsigned int trunk_capacity;
           bool assisted_braking;
    public:
    Sedan(
        const unsigned int id,
        const std::string name,
        const std::string brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const std::string image_path,
        const unsigned int habitability,
        const unsigned int trunk_capacity,
        const bool assisted_braking
        );
    unsigned int getHabitability() const;
    unsigned int getCapacity() const;
    bool getAssisted_brakingn() const;

    Sedan& setHabitability(unsigned int);
    Sedan& setCapacity(unsigned int);
    Sedan& setAssisted_braking(bool);

    virtual char evaluetion() const;
    virtual unsigned int finalPrice() const;
    virtual void accept(ConstVisitor& visitor) const;
    // virtual void print(std::ostream&, const Car&);

    // std::ostream& printSedan(std::ostream&, const Sedan&);
};

}

#endif
// Suv
// 	Trazione (4x4 o no)
// 	Cerchi (misura)
// 	Ripresa
