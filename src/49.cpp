#include <iostream>
#include <typeinfo>

struct Vehicle {
    virtual ~Vehicle() = 0;
};

Vehicle::~Vehicle()
{
}

struct Bus : Vehicle {
    const char* getDetails() const
    {
        return "Bus";
    }
    ~Bus()
    {
    }
};

struct Car : Vehicle {
    const char* getDetails() const
    {
        return "Car";
    }
    ~Car()
    {
    }
};

struct Bike : Vehicle {
    const char* getDetails() const
    {
        return "Bike";
    }
    ~Bike()
    {
    }
};

int main()
{
    Vehicle* vehicles[] { new Bus {}, new Car {}, new Bike {} };

    for (auto* vehicle : vehicles) {
        std::cout << "Its a ";
        if (typeid(*vehicles) == typeid(Bus)) {
            std::cout << dynamic_cast<Bus*>(vehicle)->getDetails() << "\n";
        } else if (typeid(*vehicles) == typeid(Car)) {
            std::cout << dynamic_cast<Car*>(vehicle)->getDetails() << "\n";
        } else if (typeid(*vehicles) == typeid(Bike)) {
            std::cout << dynamic_cast<Bike*>(vehicle)->getDetails() << "\n";
        }
    }

    delete vehicles[0];
    delete vehicles[1];
    delete vehicles[2];
}