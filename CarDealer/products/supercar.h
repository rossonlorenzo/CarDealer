#ifndef SUPERCAR_H
#define SUPERCAR_H
#include <iostream>
#include "car.h"
#include "constvisitor.h"

namespace products {

class Super_car : public Car{
    private:
           unsigned int driving_modes;
           unsigned int aerodynamics;
           unsigned int acceleration;
    public:
    Super_car(
        const unsigned int id,
        const std::string name,
        const std::string brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const std::string image_path,
        const unsigned int driving_modes,
        const unsigned int aerodynamics,
        const unsigned int acceleration
        );
    unsigned int getDrivingM() const;
    unsigned int getAerodynamics() const;
    unsigned int getAcceleration() const;

    Super_car& setDrivingM(const unsigned int);
    Super_car& setAerodynamics(const unsigned int);
    Super_car& setAcceleration(const unsigned int);

    virtual char evaluetion() const;
    virtual unsigned int finalPrice() const;
    virtual void accept(ConstVisitor& visitor) const;
    // virtual void print(std::ostream&, const Car&);

    // std::ostream& printSuper_car(std::ostream&, const Super_car&);
};

}

#endif
// Suv
// 	Trazione (4x4 o no)
// 	Cerchi (misura)
// 	Ripresa
