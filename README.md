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
