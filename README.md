# System Design and LLD Practice

This repository is a beginner-friendly study workspace for **Low Level Design (LLD)**, **object-oriented design principles**, and **design patterns** using C++.

The goal is simple: a new learner should be able to open the repo, know where to start, compile examples, and revise concepts without guessing.

## Start Here

Follow this order if you are new:

1. Learn OOP basics first: class, object, inheritance, abstraction, encapsulation, and polymorphism.
2. Study [Principles](Principles/README.md): SOLID, DRY, KISS, and YAGNI.
3. Study [Design Patterns](DesignPatterns/README.md): reusable solutions for common design problems.
4. Practice [Examples](Examples/README.md): small LLD-style systems.
5. Revise each topic using the README inside its folder.

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
|   `-- Behavioral/
|       |-- README.md
|       |-- command-design-pattern/
|       |-- Iterator-design-pattern/
|       |-- ObserverDesignPattern/
|       `-- StrategyDesignPattern/
|-- Principles/
|   |-- README.md
|   |-- SOLID/
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
|   `-- VehicleManagement/
|-- README.md
`-- .gitignore
```

## How to Compile and Run

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

## Learning Method

For every principle, pattern, or example, ask:

- What problem does it solve?
- What is the main idea?
- What are the important classes?
- How do the classes interact?
- When should I use it?
- What are the trade-offs?

## What This Repo Is Good For

- learning LLD fundamentals
- understanding class responsibilities
- revising design patterns
- practicing small C++ examples
- preparing for object-oriented design interviews

## What This Repo Is Not

This is not a complete high-level distributed system design course. For large-scale system design, you also need topics like APIs, databases, caching, queues, load balancing, consistency, scaling, and monitoring.

## Recommended Daily Practice

1. Pick one folder.
2. Read the README first.
3. Read the `.cpp` file slowly.
4. Compile and run it.
5. Change one small part.
6. Explain the design in your own words.

That last step matters most. If you can explain why the classes exist, you are learning design instead of memorizing code.
