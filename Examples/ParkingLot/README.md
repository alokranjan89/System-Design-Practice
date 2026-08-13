# Parking Lot System

## Problem statement

Design a parking lot system that supports:

- parking different vehicle types
- assigning appropriate parking spots
- generating tickets for vehicles entering the lot
- finding a ticket during exit
- freeing the used spot when a vehicle leaves
- tracking entry and exit time

## Requirements

### Functional requirements

1. The system should support multiple vehicle types such as bike, car, and truck.
2. Each parking spot should belong to a specific type: bike, car, or truck.
3. A vehicle should be assigned only to a compatible spot.
4. The system should track whether a spot is available or occupied.
5. A ticket should be created when a vehicle enters the lot.
6. The ticket should store the vehicle number, spot ID, entry time, and exit time.
7. When a vehicle exits, the system should:
   - find the ticket by ID
   - find the assigned parking spot
   - free the spot
   - set the exit time
8. The system should show which spots are still available.

### Non-functional requirements

1. The code should be easy to understand and revise.
2. The design should allow future extension such as multiple floors, pricing, and payment logic.
3. The system should keep responsibilities separated between classes.

## Questions to think about

1. What is the main responsibility of `ParkingLot`?
2. What is the role of `ParkingFloor`?
3. Why do we need both `ParkingSpot` and `Ticket`?
4. How does the system decide which spot is suitable for a vehicle?
5. What happens when a vehicle exits?
6. Why is `spotId` stored in the ticket?
7. What would happen if there were many floors and many vehicles?
8. How would you extend the design to support pricing and payment?

## Class responsibilities

- `Vehicle` - represents a vehicle and stores its type and number.
- `Bike`, `Car`, `Truck` - concrete vehicle types.
- `ParkingSpot` - represents one parking slot and its occupancy state.
- `ParkingFloor` - contains multiple spots and supports finding available or specific spots.
- `Ticket` - records the entry and exit information of a vehicle.
- `ParkingLot` - manages the whole parking system, including parking and exit operations.

## UML-style diagram

```text
+------------------+
|      Vehicle     |
|------------------|
| - vehicleNumber  |
| - vehicleType    |
| + getVehicleNumber() |
| + getVehicleType()   |
+------------------+
          ^
          |
   +------+------+
   | Bike | Car | Truck
   +--------------+

+------------------+
|  ParkingSpot     |
|------------------|
| - spotId         |
| - spotType       |
| - isAvailable    |
| + parkVehicle()  |
| + removeVehicle()|
| + getSpotId()    |
+------------------+

+------------------+
| ParkingFloor     |
|------------------|
| - floorNumber    |
| - spots[]        |
| + findSpotById() |
| + findAvailableSpot() |
| + showAvailableSpots() |
+------------------+

+------------------+
| Ticket           |
|------------------|
| - ticketId       |
| - vehicleNumber  |
| - vehicleType    |
| - spotId         |
| - entryTime      |
| - exitTime       |
| + setExitTime()  |
| + displayTicket()|
+------------------+

+------------------+
| ParkingLot       |
|------------------|
| - name           |
| - floors[]       |
| - tickets[]      |
| + addFloor()     |
| + parkVehicle()  |
| + findTicketById() |
| + exitVehicle()  |
+------------------+
```

## Flow of the system

### Entry flow

1. A vehicle arrives at the parking lot.
2. The system checks the appropriate parking spot type for its vehicle type.
3. It finds an available compatible spot.
4. The spot is marked occupied.
5. A ticket is generated with the vehicle number and spot number.

### Exit flow

1. The user provides a ticket ID.
2. The system finds the ticket.
3. It looks up the parking spot by spot ID.
4. The spot becomes available again.
5. The exit time is saved.
6. The ticket is displayed with both entry and exit times.

## Simple summary

This example demonstrates how a basic parking lot system can be modeled using objects, responsibilities, and simple flow control. It is a good low-level design example because it shows how classes interact in a realistic problem.
