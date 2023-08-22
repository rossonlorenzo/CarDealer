#include "suv.h"

namespace products {

Suv::Suv(
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
    const unsigned int recovery) : Car(id, name, brand, list_price, horsepower, kilometers, doors, image_path), traction(traction), wheels(wheels), recovery(recovery) {}

bool Suv::getTraction() const{
    return traction;
}
unsigned int Suv::getWheels() const{
    return wheels;
}
unsigned int Suv::getRecovery() const{
    return recovery;
}

Suv& Suv::setTraction(const bool newTraction){
    this->traction = newTraction;
    return *this;
}
Suv& Suv::setWheels(const unsigned int newWheels){
    this->wheels = newWheels;
    return *this;
}
Suv& Suv::setRecovery(const unsigned int newRecovery){
    this->recovery = newRecovery;
    return *this;
}

char Suv::evaluetion() const{
    char ris='C';
    if(traction){
        if(wheels >=19){
            ris='B';
            if(recovery >3)
                ris='A';
        }
    };
    return ris;
}

unsigned int Suv::finalPrice() const{
  int ris = this->estimation();
    switch(this->evaluetion()){
        case 'C' : ris= ris+(ris*2)/100; break;
        case 'B' : ris= ris+(ris*5)/100; break;
        case 'A' : ris= ris+(ris*7)/100; break;
    }
    return ris;
}

void Suv::accept(ConstVisitor& visitor) const {
    visitor.visit(*this);
}
}
