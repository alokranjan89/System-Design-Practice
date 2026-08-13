#include <iostream>
#include <string>
using namespace std;

enum class VehicleType
{
    BIKE,
    CAR,
    TRUCK
};

class Vehicle
{
protected:
    string vehicleNumber;
    VehicleType vehicleType;

public:
    Vehicle(string vehicleNumber, VehicleType vehicleType) : vehicleNumber(vehicleNumber), vehicleType(vehicleType) {}
};

class Bike : public Vehicle
{
public:
    Bike(string vehicleNumber)
        : Vehicle(vehicleNumber, VehicleType::BIKE)
    {
    }
};

class Car : public Vehicle
{
public:
    Car(string vehicleNumber)
        : Vehicle(vehicleNumber, VehicleType::CAR)
    {
    }
};

class Truck : public Vehicle
{
public:
    Truck(string vehicleNumber)
        : Vehicle(vehicleNumber, VehicleType::TRUCK)
    {
    }
};

class ParkingSpot{
    
}