#include "car.h"
#include "linkedlist.h"

namespace products {

Car::Car(
    const unsigned int id,
    const std::string name,
    const std::string brand,
    const unsigned int list_price,
    const unsigned int horsepower,
    const unsigned int kilometers,
    const bool doors,
    const std::string image_path) : id(id), name(name), brand(brand), list_price(list_price), horsepower(horsepower),
                        kilometers(kilometers), doors(doors), image_path(image_path){};

Car::~Car(){
}

unsigned int Car::getId() const {
    return id;
}

const std::string& Car::getName() const {
    return name;
}

const std::string& Car::getBrand() const {
    return brand;
}

unsigned int Car::getList_price() const{
    return list_price;
}

unsigned int Car::getHorses() const{
    return horsepower;
}

unsigned int Car::getKilo() const{
    return kilometers;
}

bool Car::getDoors() const {
    return doors;
}

const std::string& Car::getImage() const{
    return image_path;
}

Car& Car::setName(std::string newName){
    this->name = newName;
    return *this;
}

Car& Car::setBrand(std::string newBrand){
    this->brand = newBrand;
    return *this;
}

Car& Car::setPrice(unsigned int newPrice){
    this->list_price = newPrice;
    return *this;
}

Car& Car::setHorses(unsigned int newHorses){
    this->horsepower = newHorses;
    return *this;
}

Car& Car::setKilo(unsigned int newKilo){
    this->kilometers = newKilo;
    return *this;
}

Car& Car::setDoors(bool newDoors){
    this->doors = newDoors;
    return *this;
}

Car& Car::setImage(std::string newImage){
    this->image_path = newImage;
    return *this;
}


unsigned int Car::estimation () const{
    int ris =0;
        if(kilometers==0)   ris = list_price;
        else if(kilometers>0 && kilometers<20000)    ris = list_price-(list_price*10)/100;
        else if(kilometers>=20000 && kilometers<50000)    ris = list_price-(list_price*25)/100;
        else if(kilometers>=50000 && kilometers<1000000)    ris = list_price-(list_price*50)/100;
        if(kilometers>=100000)   ris = list_price-(list_price*70)/100;
    return ris;
}
}
