#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "constvisitor.h"
namespace  products{

class Car{
    private:
            unsigned int id;
            std::string name;
            std::string brand;
            unsigned int list_price;
            unsigned int horsepower;
            unsigned int kilometers;
            bool doors;
            std::string image_path;
    protected:
    Car(
        const unsigned int id,
        const std::string name,
        const std::string brand,
        const unsigned int list_price,
        const unsigned int horsepower,
        const unsigned int kilometers,
        const bool doors,
        const std::string image_path
    );
    public:
    virtual ~Car();

    unsigned int getId() const;
    const std::string& getName() const;
    const std::string& getBrand() const;
    unsigned int getList_price() const;
    unsigned int getHorses() const;
    unsigned int getKilo() const;
    bool getDoors() const;
    const std::string& getImage() const;

    Car& setName(const std::string);
    Car& setBrand(const std::string);
    Car& setPrice(const unsigned int);
    Car& setHorses(const unsigned int);
    Car& setKilo(const unsigned int);
    Car& setDoors(const bool);
    Car& setImage(const std::string);

    unsigned int estimation () const;
    virtual char evaluetion() const =0;
    virtual unsigned int finalPrice() const =0;

     virtual void accept(ConstVisitor& visitor) const =0;


    // virtual void print(std::ostream&, const Car&) =0;

    // friend std::ostream& printCar(std::ostream&, const Car&);
};

}

#endif
    //risolvere sta roba della stampa anche se serve solo per debbugging
    //friend virtual std::ostream& operator<<(std::ostream&, const Car&)=0;
    //virtual void print(std::ostream&, const Car&)=0;
