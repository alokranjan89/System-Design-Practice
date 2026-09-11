# Parking Lot Management System

This project is a simple object-oriented parking lot simulation in C++. It models how a parking lot accepts vehicles, assigns parking spots, creates tickets, calculates pricing, and processes payments.

## Interview Style Answer

### Q: How would you design a parking lot system?

I would design it using a layered object-oriented model where each class has one responsibility. The system should support vehicle entry, vehicle exit, spot allocation, ticket generation, and payment calculation.

At a high level, the design has four major parts:

- Vehicle management
- Parking space management
- Ticket and pricing logic
- Payment processing

The key idea is to separate responsibility across classes so the code remains easy to extend and maintain.

### Q: What classes would you create?

I would create these core classes:

- `Vehicle` : base class for all vehicle types
- `Bike`, `Car`, `Truck` : concrete vehicle types
- `VehicleFactory` : creates the correct vehicle object
- `ParkingSpot` : represents one slot for a specific vehicle type
- `ParkingFloor` : manages parking spots on one level
- `Ticket` : stores check-in details like vehicle, floor, and spot
- `Gate` : base class for entry and exit gates
- `EntryGate`, `ExitGate` : concrete gate types
- `ParkingLot` : main manager for floors, gates, and tickets
- `PricingStrategy` : abstraction for pricing rules
- `TimeBasedPricing`, `EventBasedPricing` : concrete pricing models
- `PaymentStrategy` : abstraction for payment methods
- `CashPayment`, `CardPayment` : concrete payment methods
- `ParkingProcessor` : coordinates parking and exit operations

### Q: How does the system allocate a parking spot?

When a vehicle enters, the parking lot checks all floors and looks for the first available spot that matches the vehicle type. This is done by the `findAvailableSpot()` method.

For example:

- bike can park only in bike spots
- car can park only in car spots
- truck can park only in truck spots

This ensures proper allocation and prevents invalid parking.

### Q: How do tickets work?

Each ticket stores:

- ticket ID
- vehicle reference
- floor number
- parking spot ID
- entry time

The `Ticket` object is generated when a vehicle enters and is later used to calculate fees when the car exits.

### Q: How is pricing handled?

Pricing is designed using the Strategy Pattern. Instead of hardcoding pricing rules inside the parking lot logic, the system uses a `PricingStrategy` interface.

Example pricing strategies:

- `TimeBasedPricing` : charges based on duration
- `EventBasedPricing` : fixed charge for event-related parking

This makes it easy to add new pricing models without changing the parking logic.

### Q: How is payment handled?

Payment is also modeled using the Strategy Pattern. The system chooses a payment method such as cash or card, and then the `PaymentProcessor` executes it.

This is a good design because:

- payment methods are independent
- new payment types can be added easily
- the payment flow is separated from parking logic

### Q: What design patterns are used here?

This project demonstrates several common object-oriented design patterns:

- Factory Pattern : `VehicleFactory`
- Strategy Pattern : `PricingStrategy` and `PaymentStrategy`
- Composition : `ParkingLot` contains floors and gates
- Encapsulation : each class hides its internal details
- Inheritance : vehicle, gate, and payment hierarchy

### Q: Why is this a good system design?

This design is good because it follows clean object-oriented principles:

- each class has one responsibility
- behavior is easy to extend
- pricing and payment logic can change independently
- the code is readable and maintainable
- the system is easy to scale with more floors, spots, or payment methods

### Q: What are the main limitations?

This is a basic implementation and does not include advanced features such as:

- multiple parking lots in one city
- concurrent vehicle handling
- user authentication or admin panels
- database persistence
- real-time availability tracking
- support for monthly subscriptions
- dynamic pricing based on demand

## System Flow

1. A vehicle is created through `VehicleFactory`
2. `ParkingLot` searches for an available matching spot
3. The spot is assigned and the vehicle is parked
4. A `Ticket` is generated with entry timestamp
5. When the vehicle exits, the ticket is retrieved
6. Pricing strategy calculates the amount
7. Payment strategy processes the payment
8. The parking spot is released and marked available

## Key Concept Coverage

This example is commonly used to explain:

- inheritance
- polymorphism
- abstraction
- encapsulation
- design patterns
- object interaction in real-world systems

## Files in This Example

- `parkinglot.cpp` : complete implementation
- `README.md` : problem explanation and interview-style design answer

## How to Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\parkinglot"
g++ -std=c++17 -Wall -Wextra parkinglot.cpp -o parkinglot.exe
./parkinglot.exe
```

## Example Interview Summary

A parking lot system can be modeled as a collection of floors, parking spots, vehicles, tickets, and payment strategies. The main challenge is to manage vehicle-to-slot matching and maintain accurate billing. In a good design, responsibilities are separated into classes, and behavior is controlled through abstractions such as factory and strategy patterns. This approach makes the system modular, extensible, and easier to interview about during technical discussions.

## Quick Revision Notes

- Use `VehicleFactory` for creating specific vehicle types
- Use `ParkingSpot` to validate correct vehicle matching
- Use `ParkingLot` as the central coordinator
- Use `PricingStrategy` to separate billing logic from flow control
- Use `PaymentStrategy` to support different payment methods
- Use `Ticket` to track vehicle entry and exit details

This is a clean beginner-to-intermediate design for explaining OOP and design patterns in C++.
