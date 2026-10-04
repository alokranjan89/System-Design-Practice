# Parking Lot System

A small C++ object-oriented design for managing vehicle entry, parking spot allocation, ticketing, pricing, and payment.

## What this system does

- Accepts vehicles of type `Bike`, `Car`, and `Truck`
- Finds an available matching spot on a floor
- Creates a ticket with entry time and location
- Calculates parking fee using a pricing strategy
- Processes payment using a payment strategy
- Releases the spot when the vehicle exits

## Core classes

- `Vehicle` and derived types: `Bike`, `Car`, `Truck`
- `VehicleFactory`: creates the correct vehicle instance
- `ParkingSpot`: represents one slot with a supported vehicle type
- `ParkingFloor`: holds multiple parking spots
- `Ticket`: stores entry details used for billing
- `ParkingLot`: manages floors, gates, and tickets
- `PricingStrategy`: abstraction for fee calculation
- `TimeBasedPricing` / `EventBasedPricing`: concrete pricing rules
- `PaymentStrategy`: abstraction for payment modes
- `CashPayment` / `CardPayment`: concrete payment methods
- `ParkingProcessor`: coordinates entry and exit flow

## UML class diagram

The class diagram is stored in a separate file: [parkinglot-uml.mmd](./parkinglot-uml.mmd)

You can open it in any Mermaid-compatible viewer or editor.

## Flow

1. Vehicle is created using `VehicleFactory`
2. `ParkingLot` searches for a matching available spot
3. `ParkingSpot` is assigned and vehicle is parked
4. `Ticket` is generated with entry timestamp
5. On exit, pricing strategy calculates the fee
6. Payment strategy processes the charge
7. The parked spot is released

## How to run

```powershell
cd "C:\Users\bhart\OneDrive\Desktop\System-Design-Practice\Examples\parkinglot"
g++ -std=c++17 -Wall -Wextra parkinglot.cpp -o parkinglot.exe
./parkinglot.exe
```


This example focuses on design clarity rather than production-scale features like multi-lot management, concurrency, or database storage.
