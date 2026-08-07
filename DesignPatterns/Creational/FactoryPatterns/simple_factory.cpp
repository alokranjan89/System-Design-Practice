#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void drive() = 0;

    Vehicle() {}

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Car\n";
    }
};

class Bike : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Bike\n";
    }
};

class Truck : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Truck\n";
    }
};

// Factory
class vehicleFactory
{
public:
    static Vehicle *createVehicle(int choice)
    {
        if (choice == 1)
            return new Car();

        if (choice == 2)
            return new Bike();

        if (choice == 3)
            return new Truck();

        return nullptr;
    }
};

int main()
{
    int choice;
    cin >> choice;

    Vehicle *vehicle = vehicleFactory::createVehicle(choice);
    if (vehicle)
    {
        vehicle->drive();
        delete vehicle;
    }
}