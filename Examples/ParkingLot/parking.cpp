#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Vehicle categories used by the parking system.
// This helps the system decide which kind of spot a vehicle needs.
enum class VehicleType
{
    BIKE,
    CAR,
    TRUCK
};

// Different parking spot sizes based on vehicle type.
enum class SpotType
{
    BIKE,
    CAR,
    TRUCK
};

// Base class for all vehicles in the system.
// Every vehicle has a registration number and a type.
class Vehicle
{
protected:
    string vehicleNumber;
    VehicleType vehicleType;

public:
    Vehicle(string vehicleNumber, VehicleType vehicleType)
        : vehicleNumber(vehicleNumber),
          vehicleType(vehicleType)
    {
    }
    string getVehicleNumber()
    {
        return vehicleNumber;
    }

    VehicleType getVehicleType()
    {
        return vehicleType;
    }
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

// A single parking slot in the parking lot.
// It knows its size, its ID, and whether it is currently occupied.
class ParkingSpot
{
private:
    int spotId;
    SpotType spotType;
    bool isAvailable;

public:
    ParkingSpot(int spotId, SpotType spotType)
        : spotId(spotId),
          spotType(spotType),
          isAvailable(true)
    {
    }

    bool getIsAvailable()
    {
        return isAvailable;
    }

    SpotType getSpotType()
    {
        return spotType;
    }

    int getSpotId()
    {
        return spotId;
    }

    // Mark the spot as occupied when a vehicle enters.
    void parkVehicle()
    {
        if (!isAvailable)
        {
            cout << "Spot is already occupied." << endl;
            return;
        }

        isAvailable = false;
        cout << "Vehicle parked successfully in spot " << spotId << "." << endl;
    }

    // Mark the spot as free when a vehicle exits.
    void removeVehicle()
    {
        if (!isAvailable)
        {
            isAvailable = true;
            cout << "Vehicle removed successfully." << endl;
        }
        else
        {
            cout << "Parking spot is already available." << endl;
        }
    }
};

// One floor in the parking lot.
// It contains many parking spots and helps find a compatible free spot.
class ParkingFloor
{
private:
    int floorNumber;
    vector<ParkingSpot *> spots;

public:
    ParkingFloor(int floorNumber, vector<ParkingSpot *> spots)
        : floorNumber(floorNumber),
          spots(spots)
    {
    }

    void addSpot(ParkingSpot *spot)
    {
        spots.push_back(spot);
    }

    // Search for an empty spot of the correct size for this vehicle type.
    ParkingSpot *findAvailableSpot(SpotType type)
    {
        for (ParkingSpot *spot : spots)
        {
            if (spot->getIsAvailable() &&
                spot->getSpotType() == type)
            {
                return spot;
            }
        }

        return nullptr;
    }

    // Used during exit flow: find the exact parking spot from the ticket.
    ParkingSpot *findSpotById(int spotId)
    {
        for (ParkingSpot *spot : spots)
        {
            if (spot->getSpotId() == spotId)
            {
                return spot;
            }
        }

        return nullptr;
    }

    void showAvailableSpots()
    {
        cout << "Available spots on Floor "
             << floorNumber << ":" << endl;

        for (ParkingSpot *spot : spots)
        {
            if (spot->getIsAvailable())
            {
                cout << "Spot ID: "
                     << spot->getSpotId() << endl;
            }
        }
    }
};

// Ticket created when a vehicle enters the parking lot.
// It stores where the vehicle parked and when it entered/exited.
class Ticket
{
private:
    int ticketId;
    string vehicleNumber;
    VehicleType vehicleType;
    int spotId;
    string entryTime;
    string exitTime;

public:
    Ticket(int ticketId,
           string vehicleNumber,
           VehicleType vehicleType,
           int spotId,
           string entryTime)
        : ticketId(ticketId),
          vehicleNumber(vehicleNumber),
          vehicleType(vehicleType),
          spotId(spotId),
          entryTime(entryTime),
          exitTime("")
    {
    }

    int getTicketId()
    {
        return ticketId;
    }

    int getSpotId() const
    {
        return spotId;
    }

    // Save exit time when the vehicle leaves the parking lot.
    void setExitTime(string time)
    {
        exitTime = time;
    }

    void displayTicket()
    {
        cout << "Ticket ID: " << ticketId << endl;
        cout << "Vehicle Number: " << vehicleNumber << endl;
        cout << "Spot ID: " << spotId << endl;
        cout << "Entry Time: " << entryTime << endl;
        cout << "Exit Time: " << exitTime << endl;
    }
};

// The full parking lot system.
// It manages floors, ticket records, parking, and exit operations.
class ParkingLot
{
private:
    string name;
    vector<ParkingFloor *> floors;
    vector<string> entrances;
    vector<string> exits;
    vector<Ticket *> tickets;

public:
    ParkingLot(string name)
        : name(name)
    {
    }

    void addFloor(ParkingFloor *floor)
    {
        floors.push_back(floor);
    }

    void addEntrance(string entrance)
    {
        entrances.push_back(entrance);
    }

    void addExit(string exit)
    {
        exits.push_back(exit);
    }

    // Find the ticket created earlier when the vehicle entered.
    Ticket *findTicketById(int ticketId)
    {
        for (Ticket *ticket : tickets)
        {
            if (ticket->getTicketId() == ticketId)
            {
                return ticket;
            }
        }

        return nullptr;
    }

    // Entry flow: find a free suitable spot and generate a ticket.
    void parkVehicle(Vehicle *vehicle)
    {
        SpotType requiredSpot = SpotType::CAR;

        if (vehicle->getVehicleType() == VehicleType::BIKE)
        {
            requiredSpot = SpotType::BIKE;
        }
        else if (vehicle->getVehicleType() == VehicleType::TRUCK)
        {
            requiredSpot = SpotType::TRUCK;
        }

        for (ParkingFloor *floor : floors)
        {
            ParkingSpot *spot = floor->findAvailableSpot(requiredSpot);

            if (spot != nullptr)
            {
                spot->parkVehicle();

                int ticketId = static_cast<int>(tickets.size()) + 1;
                Ticket *ticket = new Ticket(ticketId,
                                            vehicle->getVehicleNumber(),
                                            vehicle->getVehicleType(),
                                            spot->getSpotId(),
                                            "09:00 AM");
                tickets.push_back(ticket);

                cout << "Vehicle "
                     << vehicle->getVehicleNumber()
                     << " parked successfully in spot "
                     << spot->getSpotId() << "." << endl;
                cout << "Generated Ticket ID: " << ticketId << endl;
                return;
            }
        }

        cout << "No parking spot available." << endl;
    }

    // Make the spot available again when the vehicle leaves.
    void removeVehicle(ParkingSpot *spot)
    {
        if (spot != nullptr)
        {
            spot->removeVehicle();
            cout << "Vehicle exited successfully." << endl;
        }
    }

    // Exit flow: ticket -> find spot -> free spot -> set exit time.
    void exitVehicle(int ticketId)
    {
        Ticket *ticket = findTicketById(ticketId);

        if (ticket == nullptr)
        {
            cout << "Ticket not found." << endl;
            return;
        }

        ParkingSpot *spot = nullptr;

        for (ParkingFloor *floor : floors)
        {
            spot = floor->findSpotById(ticket->getSpotId());
            if (spot != nullptr)
            {
                break;
            }
        }

        if (spot == nullptr)
        {
            cout << "Parking spot not found for the ticket." << endl;
            return;
        }

        removeVehicle(spot);
        ticket->setExitTime("06:30 PM");

        cout << "Exit processed for ticket ID: " << ticketId << endl;
        cout << "Ticket details:" << endl;
        ticket->displayTicket();
    }
};

int main()
{
    // This is the main flow of the example:
    // 1. Create parking spots
    // 2. Add them to a floor
    // 3. Park vehicles
    // 4. Generate tickets
    // 5. Exit the vehicle and free the spot
    ParkingLot parkingLot("City Mall Parking");

    ParkingSpot spot1(1, SpotType::CAR);
    ParkingSpot spot2(2, SpotType::BIKE);
    ParkingSpot spot3(3, SpotType::TRUCK);

    vector<ParkingSpot *> spots = {
        &spot1,
        &spot2,
        &spot3};

    ParkingFloor floor1(1, spots);
    parkingLot.addFloor(&floor1);

    Car car("ABC-123");
    Bike bike("BIKE-77");

    cout << "\n--- Available Spots Before Parking ---\n";
    floor1.showAvailableSpots();

    cout << "\n--- Parking Car ---\n";
    parkingLot.parkVehicle(&car);

    cout << "\n--- Parking Bike ---\n";
    parkingLot.parkVehicle(&bike);

    cout << "\n--- Exit Flow Test ---\n";
    parkingLot.exitVehicle(1);

    cout << "\n--- Available Spots After Exit ---\n";
    floor1.showAvailableSpots();

    return 0;
}