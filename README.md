# System Design and LLD Practice

This repository is a structured C++ practice workspace for **Low Level Design (LLD)**, **object-oriented design**, **SOLID principles**, and **design patterns**.

The purpose of this repo is to make design concepts easy to revise and easy to practice. Each topic is organized with a focused README and small C++ examples so that a learner can understand the problem, study the class design, compile the code, and explain the solution clearly.

## Learning Roadmap

Follow this order if you are new to LLD:

1. Learn OOP fundamentals: class, object, inheritance, abstraction, encapsulation, and polymorphism.
2. Study [design principles](Principles/README.md): SOLID, DRY, KISS, and YAGNI.
3. Study [design patterns](DesignPatterns/README.md): reusable object-oriented solutions.
4. Practice [LLD examples](Examples/README.md): small real-world systems.
5. Revisit each folder README and explain the design in your own words.

## Progress Summary

| Area | Completed | Total | Status |
|---|---:|---:|---|
| Creational GoF Patterns | 5 | 5 | Complete |
| Structural GoF Patterns | 1 | 7 | In Progress |
| Behavioral GoF Patterns | 6 | 11 | In Progress |
| Classic GoF Design Patterns | 12 | 23 | In Progress |
| Extra Practical Patterns | 1 | 1 | Complete |

## Design Pattern Checklist

### Creational Patterns

| Status | Pattern | Purpose | Location |
|---|---|---|---|
| [x] | Factory Method | Let subclasses decide which object to create | [Factory Patterns](DesignPatterns/Creational/FactoryPatterns/README.md) |
| [x] | Abstract Factory | Create families of related objects | [Factory Patterns](DesignPatterns/Creational/FactoryPatterns/README.md) |
| [x] | Builder | Build complex objects step by step | [Builder](DesignPatterns/Creational/Builder/README.md) |
| [x] | Prototype | Create objects by cloning existing objects | [Prototype](DesignPatterns/Creational/Prototype/README.md) |
| [x] | Singleton | Ensure a class has only one shared instance | [Singleton](DesignPatterns/Creational/Singleton/README.md) |
| [x] | Simple Factory | Centralize basic object creation logic | [Factory Patterns](DesignPatterns/Creational/FactoryPatterns/README.md) |

### Structural Patterns

| Status | Pattern | Purpose | Location |
|---|---|---|---|
| [x] | Adapter | Make incompatible interfaces work together | [Structural](DesignPatterns/Structural/README.md) |
| [ ] | Bridge | Separate abstraction from implementation | Planned |
| [ ] | Composite | Treat individual objects and groups uniformly | Planned |
| [ ] | Decorator | Add behavior without changing the original class | Planned |
| [ ] | Facade | Provide a simple interface over a complex subsystem | Planned |
| [ ] | Flyweight | Share reusable objects to reduce memory usage | Planned |
| [ ] | Proxy | Control access to another object | Planned |

### Behavioral Patterns

| Status | Pattern | Purpose | Location |
|---|---|---|---|
| [x] | Strategy | Choose interchangeable behavior at runtime | [Strategy](DesignPatterns/Behavioral/StrategyDesignPattern/README.md) |
| [x] | Observer | Notify dependent objects when state changes | [Observer](DesignPatterns/Behavioral/ObserverDesignPattern/README.md) |
| [x] | Iterator | Traverse a collection without exposing internals | [Iterator](DesignPatterns/Behavioral/Iterator-design-pattern/README.md) |
| [x] | Command | Encapsulate a request as an object | [Command](DesignPatterns/Behavioral/command-design-pattern/README.md) |
| [ ] | Chain of Responsibility | Pass a request through a chain of handlers | Planned |
| [x] | Mediator | Centralize communication between objects | [Mediator](DesignPatterns/Behavioral/Mediator-design-pattern/README.md) |
| [ ] | Memento | Capture and restore object state | Planned |
| [x] | State | Change behavior when internal state changes | [State](DesignPatterns/Behavioral/state-design-pattern/README.md) |
| [ ] | Template Method | Define an algorithm skeleton in a base class | Planned |
| [ ] | Visitor | Add operations without changing object classes | Planned |
| [ ] | Interpreter | Represent and evaluate grammar or expressions | Planned |

## Repository Structure

```text
System Design/
|-- DesignPatterns/
|   |-- README.md
|   |-- Creational/
|   |   |-- README.md
|   |   |-- Builder/
|   |   |-- FactoryPatterns/
|   |   |-- Prototype/
|   |   `-- Singleton/
|   |-- Structural/
|   |   |-- README.md
|   |   `-- Adapter/
|   `-- Behavioral/
|       |-- README.md
|       |-- command-design-pattern/
|       |-- Iterator-design-pattern/
|       |-- Mediator-design-pattern/
|       |-- ObserverDesignPattern/
|       |-- state-design-pattern/
|       `-- StrategyDesignPattern/
|-- Principles/
|   |-- README.md
|   |-- Solid/
|   |-- DRY/
|   |-- KISS/
|   `-- YAGNI/
|-- Examples/
|   |-- README.md
|   |-- AnimalManagement/
|   |-- AtmCard/
|   |-- BankManagement/
|   |-- EmployeeManagement/
|   |-- HospitalManagement/
|   |-- LibraryManagement/
|   |-- ParkingLot/
|   |-- Smart Notification System/
|   `-- VehicleManagement/
|-- README.md
`-- .gitignore
```

## How To Compile And Run

Compile one file at a time.

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\BankManagement"
g++ -std=c++17 -Wall -Wextra bank_management.cpp -o bank_management.exe
./bank_management.exe
```

For any other file:

```powershell
g++ -std=c++17 -Wall -Wextra file_name.cpp -o file_name.exe
./file_name.exe
```

Generated `.exe`, `.out`, `.obj`, and `.o` files should not be committed.

## How To Study Each Topic

For every principle, pattern, or example, ask:

- What problem does it solve?
- Which classes are responsible for which behavior?
- Which object creates, owns, or uses another object?
- How does the flow start from `main()`?
- What becomes easier to change because of this design?
- What trade-off or extra complexity does this design introduce?

## LLD Practice Examples

The [Examples](Examples/README.md) folder contains small object-oriented systems such as:

- Animal Management
- ATM Card
- Bank Management
- Employee Management
- Hospital Management
- Library Management
- Parking Lot
- Smart Notification System
- Vehicle Management

These examples are useful for practicing class identification, responsibility separation, object relationships, and interview-style explanation.

## What This Repo Is Good For

- learning LLD fundamentals
- understanding class responsibilities
- revising design patterns
- practicing small C++ design examples
- preparing for object-oriented design interviews
- building confidence in explaining design decisions

## What This Repo Is Not

This is not a complete high-level distributed system design course. For large-scale system design, also study APIs, databases, caching, queues, load balancing, consistency, scaling, monitoring, and deployment architecture.

## Recommended Daily Practice

1. Pick one principle, pattern, or example.
2. Read the README first.
3. Read the `.cpp` file slowly.
4. Compile and run the code.
5. Modify one small behavior.
6. Explain the design without looking at the code.

The final step matters most. If you can explain why each class exists and how objects collaborate, you are learning design instead of memorizing code.

## Quick Revision

Use [QUICK_REVISION.md](QUICK_REVISION.md) when you want to revise only the required points quickly before practice or interviews.
