#include "sedan.h"

namespace products {

Sedan::Sedan(
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
    const bool assisted_braking) : Car(id, name, brand, list_price, horsepower, kilometers, doors, image_path), habitability(habitability), trunk_capacity(trunk_capacity), assisted_braking(assisted_braking) {}

unsigned int Sedan::getHabitability() const{
        return habitability;
}
unsigned int Sedan::getCapacity() const{
        return trunk_capacity;
}
bool Sedan::getAssisted_brakingn() const{
        return assisted_braking;
}

Sedan& Sedan::setHabitability(const unsigned int newH){
    this->habitability = newH;
    return *this;
}
Sedan& Sedan::setCapacity(const unsigned int newCapacity){
    this->trunk_capacity = newCapacity;
    return *this;
}
Sedan& Sedan::setAssisted_braking(const bool newA){
    this->assisted_braking = newA;
    return *this;
}

char Sedan::evaluetion() const{
    char ris='C';
    if(habitability>=3){
        if(trunk_capacity >=2){
            ris='B';
            if(assisted_braking)
                ris='A';
        }
    };
    return ris;
}

unsigned int Sedan::finalPrice() const{
  int ris = this->estimation();
    switch(this->evaluetion()){
        case 'C' : ris= ris+(ris*2)/100; break;
        case 'B' : ris= ris+(ris*5)/100; break;
        case 'A' : ris= ris+(ris*7)/100; break;
    }
    return ris;
}

void Sedan::accept(ConstVisitor& visitor) const {
    visitor.visit(*this);
}
}
