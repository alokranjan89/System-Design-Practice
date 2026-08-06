#include <iostream>
using namespace std;

// ==========================
// Product Interface
// ==========================
class Vehicle {
public:
    virtual void drive() = 0;

    virtual ~Vehicle() {}
};

// ==========================
// Concrete Products
// ==========================

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving Car" << endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Driving Bike" << endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() override {
        cout << "Driving Truck" << endl;
    }
};

// ==========================
// Creator (Abstract Factory)
// ==========================

class VehicleFactory {
public:

    virtual Vehicle* createVehicle() = 0;

    virtual ~VehicleFactory() {}
};

// ==========================
// Concrete Factories
// ==========================

class CarFactory : public VehicleFactory {
public:

    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
public:

    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory {
public:

    Vehicle* createVehicle() override {
        return new Truck();
    }
};

// ==========================
// Client
// ==========================

int main() {

    int choice;

    cout << "========= Vehicle Factory =========" << endl;
    cout << "1. Car" << endl;
    cout << "2. Bike" << endl;
    cout << "3. Truck" << endl;
    cout << "Enter Choice : ";

    cin >> choice;

    VehicleFactory* factory = nullptr;

    // Decide which factory to use

    switch(choice)
    {
        case 1:
            factory = new CarFactory();
            break;

        case 2:
            factory = new BikeFactory();
            break;

        case 3:
            factory = new TruckFactory();
            break;

        default:
            cout << "Invalid Choice" << endl;
            return 0;
    }

    // Factory creates object

    Vehicle* vehicle = factory->createVehicle();

    

    vehicle->drive();

    // Free memory

    delete vehicle;
    delete factory;

    return 0;
}