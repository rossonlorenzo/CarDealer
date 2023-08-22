#include "supercar.h"

namespace products {

Super_car::Super_car(
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
    const unsigned int acceleration) : Car(id, name, brand, list_price, horsepower, kilometers, doors, image_path), driving_modes(driving_modes), aerodynamics(aerodynamics), acceleration(acceleration) {}

unsigned int Super_car::getDrivingM() const{
        return driving_modes;
}
unsigned int Super_car::getAerodynamics() const{
        return aerodynamics;
}
unsigned int Super_car::getAcceleration() const{
        return acceleration;
}

Super_car& Super_car::setDrivingM(const unsigned int newDrivingM){
    this->driving_modes = newDrivingM;
    return *this;
}
Super_car& Super_car::setAerodynamics(const unsigned int newAero){
    this->aerodynamics = newAero;
    return *this;
}
Super_car& Super_car::setAcceleration(const unsigned int newAcc){
    this->acceleration = newAcc;
    return *this;
}

char Super_car::evaluetion() const{
    char ris='C';
    if(acceleration>2){
        if(aerodynamics >=3){
            ris='B';
            if(driving_modes >=3)
                ris='A';
        }
    };
    return ris;
}

unsigned int Super_car::finalPrice() const{
    int ris = this->estimation();
    switch(this->evaluetion()){
        case 'C' : ris= ris+(ris*2)/100; break;
        case 'B' : ris= ris+(ris*5)/100; break;
        case 'A' : ris= ris+(ris*7)/100; break;
    }
    return ris;
}

void Super_car::accept(ConstVisitor& visitor) const {
    visitor.visit(*this);
}
}
