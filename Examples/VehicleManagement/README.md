# Vehicle Management

This example demonstrates basic vehicle modeling with inheritance, composition, association, and polymorphism.

## Key Concepts

- `Vehicle` is an abstract base class.
- `Car`, `Bike`, and `Truck` provide different special features.
- `Vehicle` is composed with an `Engine`.
- `Driver` is associated with multiple vehicles.
- Polymorphism lets the driver call `start()`, `specialFeature()`, and `stop()` through `Vehicle*`.

## Main Classes

| Class | Responsibility |
|---|---|
| `Engine` | Starts and stops the vehicle engine |
| `Vehicle` | Base class for shared vehicle data and behavior |
| `Car` | Concrete vehicle with trunk behavior |
| `Bike` | Concrete vehicle with kick-start behavior |
| `Truck` | Concrete vehicle with cargo-loading behavior |
| `Driver` | Stores vehicles and drives them polymorphically |

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\VehicleManagement"
g++ -std=c++17 -Wall -Wextra vehicle_factory.cpp -o vehicle_factory.exe
./vehicle_factory.exe
```
