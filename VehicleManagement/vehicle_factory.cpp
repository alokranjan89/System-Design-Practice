#include <iostream>
#include <vector>
using namespace std;

class Engine
{
private:
    string engineNumber;
    int horsePower;

public:
    Engine(string number, int hp)
    {
        engineNumber = number;
        horsePower = hp;
    }

    void startEngine()
    {
        cout << "Engine Started\n";
    }

    void stopEngine()
    {
        cout << "Engine Stopped\n";
    }
};

class Vehicle
{

protected:
    int vehicleId;
    string brand;
    string model;
    int speed;

    // Composition
    Engine engine;

public:
    Vehicle(int id,
            string brand,
            string model,
            int speed,
            string engineNo,
            int hp)
        : engine(engineNo, hp)
    {
        vehicleId = id;
        this->brand = brand;
        this->model = model;
        this->speed = speed;
    }

    virtual void start()
    {
        engine.startEngine();
        cout << brand << " Started\n";
    }

    virtual void stop()
    {
        engine.stopEngine();
        cout << brand << " Stopped\n";
    }

    virtual void specialFeature() = 0;

    virtual ~Vehicle() {}
};


class Car : public Vehicle
{

public:
    Car(int id,
        string brand,
        string model,
        int speed,
        string engineNo,
        int hp)
        : Vehicle(id, brand, model, speed, engineNo, hp)
    {
    }

    void openTrunk()
    {
        cout << "Opening Car Trunk\n";
    }

    void specialFeature() override
    {
        openTrunk();
    }
};



class Bike : public Vehicle
{

public:
    Bike(int id,
         string brand,
         string model,
         int speed,
         string engineNo,
         int hp)
        : Vehicle(id, brand, model, speed, engineNo, hp)
    {
    }

    void kickStart()
    {
        cout << "Bike Kick Started\n";
    }

    void specialFeature() override
    {
        kickStart();
    }
};



class Truck : public Vehicle
{

public:
    Truck(int id,
          string brand,
          string model,
          int speed,
          string engineNo,
          int hp)
        : Vehicle(id, brand, model, speed, engineNo, hp)
    {
    }

    void loadCargo()
    {
        cout << "Truck Loading Cargo\n";
    }

    void specialFeature() override
    {
        loadCargo();
    }
};


class Driver
{

private:
    int driverId;
    string name;

    // Association
    vector<Vehicle *> vehicles;

public:
    Driver(int id, string name)
    {
        driverId = id;
        this->name = name;
    }

    void addVehicle(Vehicle *vehicle)
    {
        vehicles.push_back(vehicle);
    }

    void driveVehicles()
    {
        cout << "\nDriver : " << name << "\n\n";

        for (Vehicle *vehicle : vehicles)
        {
            vehicle->start();
            vehicle->specialFeature();
            vehicle->stop();

            cout << "---------------------\n";
        }
    }
};


int main()
{
    Driver driver(1, "Alok");

    Car car(
        101,
        "BMW",
        "X5",
        220,
        "ENG001",
        250);

    Bike bike(
        102,
        "Yamaha",
        "R15",
        150,
        "ENG002",
        150);

    Truck truck(
        103,
        "Tata",
        "LPT",
        100,
        "ENG003",
        400);

    driver.addVehicle(&car);
    driver.addVehicle(&bike);
    driver.addVehicle(&truck);

    driver.driveVehicles();

    return 0;
}