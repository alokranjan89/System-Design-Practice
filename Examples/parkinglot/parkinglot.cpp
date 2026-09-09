#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <unordered_map>

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
    string number;
    VehicleType type;

public:
    // const string&:
    // Pass string by reference to avoid unnecessary copy
    // const ensures that we don't modify the original string.

    Vehicle(
        const string &number,
        VehicleType type)
        : number(number),
          type(type)
    {
    }

    virtual ~Vehicle() = default;

    string getNumber() const
    {
        return number;
    }

    VehicleType getType() const
    {
        return type;
    }
};

class Bike : public Vehicle
{
public:
    Bike(const string &number)
        : Vehicle(
              number,
              VehicleType::BIKE)
    {
    }
};

class Car : public Vehicle
{
public:
    Car(const string &number)
        : Vehicle(
              number,
              VehicleType::CAR)
    {
    }
};

class Truck : public Vehicle
{
public:
    Truck(const string &number)
        : Vehicle(
              number,
              VehicleType::TRUCK)
    {
    }
};
class VehicleFactory
{
public:
    static unique_ptr<Vehicle> createVehicle(
        VehicleType type,
        const string &number)
    {
        if (type == VehicleType::BIKE)
        {
            return make_unique<Bike>(number);
        }

        if (type == VehicleType::CAR)
        {
            return make_unique<Car>(number);
        }

        if (type == VehicleType::TRUCK)
        {
            return make_unique<Truck>(number);
        }

        return nullptr;
    }
};

class ParkingSpot
{
private:
    int id;

    VehicleType supportedVehicleType;

    // ParkingSpot does NOT own Vehicle.
    // It only keeps a reference to the vehicle parked here.

    Vehicle *vehicle;

public:
    ParkingSpot(
        int id,
        VehicleType supportedVehicleType)
        : id(id),
          supportedVehicleType(supportedVehicleType),
          vehicle(nullptr)
    {
    }

    int getId() const
    {
        return id;
    }

    bool isAvailable() const
    {
        return vehicle == nullptr;
    }

    bool canPark(Vehicle *vehicle) const
    {
        // Protect against nullptr

        if (vehicle == nullptr)
            return false;

        // Spot already occupied

        if (!isAvailable())
            return false;

        // Check whether vehicle type matches
        // the type supported by this spot

        return vehicle->getType() ==
               supportedVehicleType;
    }

    void park(Vehicle *vehicle)
    {
        if (!canPark(vehicle))
        {
            cout << "Vehicle cannot be parked here.\n";
            return;
        }

        this->vehicle = vehicle;

        cout << "Vehicle "
             << vehicle->getNumber()
             << " parked at spot "
             << id
             << endl;
    }

    Vehicle *removeVehicle()
    {
        Vehicle *removedVehicle =
            vehicle;

        // Spot becomes available

        vehicle = nullptr;

        return removedVehicle;
    }

    Vehicle *getVehicle() const
    {
        return vehicle;
    }
};

class ParkingFloor
{
private:
    int floorNumber;

    // ParkingFloor OWNS ParkingSpots

    vector<unique_ptr<ParkingSpot>>
        parkingSpots;

public:
    ParkingFloor(int floorNumber)
        : floorNumber(floorNumber)
    {
    }

    int getFloorNumber() const
    {
        return floorNumber;
    }

    // Transfer ownership of ParkingSpot
    // from caller to ParkingFloor.

    void addParkingSpot(
        unique_ptr<ParkingSpot> spot)
    {
        parkingSpots.push_back(
            move(spot));
    }

    // Find first suitable available spot

    ParkingSpot *getAvailableSpot(
        Vehicle *vehicle)
    {
        for (auto &spot : parkingSpots)
        {
            if (spot->canPark(vehicle))
            {
                // get() gives a non-owning pointer

                return spot.get();
            }
        }

        return nullptr;
    }

    // Find a particular spot by ID

    ParkingSpot *getParkingSpot(
        int spotId)
    {
        for (auto &spot : parkingSpots)
        {
            if (spot->getId() == spotId)
            {
                return spot.get();
            }
        }

        return nullptr;
    }

    // Return non-owning pointers to spots

    vector<ParkingSpot *> getParkingSpots()
    {
        vector<ParkingSpot *> result;

        for (auto &spot : parkingSpots)
        {
            result.push_back(
                spot.get());
        }

        return result;
    }
};

class Ticket
{
private:
    int ticketId;

    // Ticket does not own Vehicle.

    Vehicle *vehicle;

    int floorNumber;

    int spotId;

    time_t entryTime;

public:
    Ticket(
        int ticketId,
        Vehicle *vehicle,
        int floorNumber,
        int spotId)
        : ticketId(ticketId),
          vehicle(vehicle),
          floorNumber(floorNumber),
          spotId(spotId)
    {
        // Store the current time
        // when ticket is created.

        entryTime = time(nullptr);
    }

    int getTicketId() const
    {
        return ticketId;
    }

    Vehicle *getVehicle() const
    {
        return vehicle;
    }

    int getFloorNumber() const
    {
        return floorNumber;
    }

    int getSpotId() const
    {
        return spotId;
    }

    time_t getEntryTime() const
    {
        return entryTime;
    }
};

enum class GateType
{
    ENTRY,
    EXIT
};

class Gate
{
protected:
    int id;

    GateType type;

public:
    Gate(
        int id,
        GateType type)
        : id(id),
          type(type)
    {
    }

    virtual ~Gate() = default;

    int getId() const
    {
        return id;
    }

    GateType getType() const
    {
        return type;
    }
};

class EntryGate : public Gate
{
public:
    EntryGate(int id)
        : Gate(
              id,
              GateType::ENTRY)
    {
    }
};

class ExitGate : public Gate
{
public:
    ExitGate(int id)
        : Gate(
              id,
              GateType::EXIT)
    {
    }
};

class ParkingLot
{
    // make_unique creates an object and returns a unique_ptr that owns it, providing automatic memory management and avoiding manual delete
private:
    string name;

    // ParkingLot owns ParkingFloors

    vector<unique_ptr<ParkingFloor>>
        parkingFloors;

    // ParkingLot owns EntryGates

    vector<unique_ptr<EntryGate>>
        entryGates;

    // ParkingLot owns ExitGates

    vector<unique_ptr<ExitGate>>
        exitGates;

    // ParkingLot owns Tickets

    unordered_map<
        int,
        unique_ptr<Ticket>>
        tickets;

    // Used to generate unique ticket IDs

    int nextTicketId;

public:
    ParkingLot(
        const string &name)
        : name(name),
          nextTicketId(1)
    {
    }

    void addFloor(
        unique_ptr<ParkingFloor> floor)
    {
        parkingFloors.push_back(
            move(floor));
    }

    void addEntryGate(
        unique_ptr<EntryGate> gate)
    {
        entryGates.push_back(
            move(gate));
    }

    void addExitGate(
        unique_ptr<ExitGate> gate)
    {
        exitGates.push_back(
            move(gate));
    }

    ParkingSpot *findAvailableSpot(
        Vehicle *vehicle,
        ParkingFloor *&selectedFloor)
    {
        for (auto &floor : parkingFloors)
        {
            ParkingSpot *spot =
                floor->getAvailableSpot(
                    vehicle);

            if (spot != nullptr)
            {
                selectedFloor =
                    floor.get();

                return spot;
            }
        }

        selectedFloor = nullptr;

        return nullptr;
    }

    Ticket *enterVehicle(
        Vehicle *vehicle)
    {
        ParkingFloor *selectedFloor =
            nullptr;

        // Find suitable parking spot

        ParkingSpot *spot =
            findAvailableSpot(
                vehicle,
                selectedFloor);

        // No spot available

        if (spot == nullptr)
        {
            cout << "No parking spot available\n";

            return nullptr;
        }

        // Park vehicle

        spot->park(vehicle);

        // Create ticket

        auto ticket =
            make_unique<Ticket>(
                nextTicketId,
                vehicle,
                selectedFloor->getFloorNumber(),
                spot->getId());

        // Keep raw pointer before
        // transferring ownership.

        Ticket *ticketPointer =
            ticket.get();

        // ParkingLot now owns the ticket

        tickets[nextTicketId] =
            move(ticket);

        // Generate next ID

        nextTicketId++;

        return ticketPointer;
    }

    Ticket *getTicket(
        int ticketId)
    {
        auto it =
            tickets.find(ticketId);

        if (it == tickets.end())
        {
            return nullptr;
        }

        return it->second.get();
    }

    ParkingFloor *getFloor(
        int floorNumber)
    {
        for (auto &floor : parkingFloors)
        {
            if (floor->getFloorNumber() == floorNumber)
            {
                return floor.get();
            }
        }

        return nullptr;
    }
};

