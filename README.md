# System Design and LLD Practice

This repository is a study collection for **Low Level Design (LLD)** and **System Design** concepts implemented in C++.

The repository is organized by pattern family and example type so related files stay grouped together.

## Repository Structure

```text
System Design/
+-- DesignPatterns/
|   +-- Creational/
|   |   +-- Builder/
|   |   +-- FactoryPatterns/
|   |   +-- Prototype/
|   |   +-- Singleton/
|   +-- Behavioral/
|       +-- ObserverDesignPattern/
|       +-- StrategyDesignPattern/
+-- Principles/
|   +-- SOLID/
|   +-- DRY/
|   +-- KISS/
|   +-- YAGNI/
+-- Examples/
|   +-- AnimalManagement/
|   +-- AtmCard/
|   +-- BankManagement/
|   +-- EmployeeManagement/
|   +-- HospitalManagement/
|   +-- LibraryManagement/
|   +-- VehicleManagement/
+-- README.md
+-- .gitignore
```

## Current Examples

- `DesignPatterns/Creational/` - creational design pattern examples and object creation strategies
- `DesignPatterns/Behavioral/` - behavioral design pattern examples
- `Principles/` - single-responsibility, DRY, KISS, YAGNI, and SOLID principle demos
- `Examples/` - general system design examples for animals, banking, library, and vehicles

## How to Use

1. Open a folder in your C++ IDE or terminal.
2. Compile the `.cpp` file in that folder with a C++ compiler.
3. Run the generated executable.

Example with `g++`:

```powershell
cd "System Design\Examples\BankManagement"
g++ -std=c++17 -Wall -Wextra bank_management.cpp -o bank_management.exe
./bank_management.exe
```

To compile any other example, move into its folder and replace the file name:

```powershell
g++ -std=c++17 -Wall -Wextra file_name.cpp -o file_name.exe
./file_name.exe
```

## Goals

- Keep each problem in its own folder
- Include short notes for each example
- Use clear and consistent file names
- Avoid storing compiled binaries in Git

## Notes

This repository is a learning workspace. The examples are kept small so they are easy to study and extend later.

## Best way to learn from this repo

This repo is best used as a foundation for building design understanding, not as a complete system design course on its own.

### Recommended learning order

1. Start with OOP basics
   - classes, objects, inheritance, abstraction, encapsulation, polymorphism
2. Study design principles
   - SOLID, DRY, KISS, YAGNI
3. Learn design patterns
   - start with creational patterns
   - then move to behavioral patterns
4. Practice the small examples
   - compile and run them one by one
   - understand each class and responsibility
5. Move to LLD problem-solving
   - think about classes, interfaces, and interactions
6. Then move to system design topics
   - scalability, databases, caching, queues, APIs, load balancing

### What this repo is good for

- learning pattern concepts
- understanding low-level design ideas
- practicing class relationships and responsibilities
- reviewing simple examples in C++

### What this repo is not enough for

- full distributed system design
- real-world production architecture decisions
- large-scale scalability questions
- deep interview-level system design discussions

### Beginner advice

Do not try to memorize patterns only. Focus on understanding:

- what problem the pattern solves
- why it is used
- when it should be used
- what the trade-offs are

If you understand the reasoning behind the design, learning becomes much easier.

## Suggested revision method

When you study a pattern, ask these 5 questions:

- What is the problem?
- What is the main idea?
- What are the key components?
- When do we use it?
- What are the advantages and disadvantages?

This method makes the notes easier to revise and remember.
