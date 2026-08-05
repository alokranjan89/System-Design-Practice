# System Design and LLD Practice

This repository is a study collection for **Low Level Design (LLD)** and **System Design** concepts implemented in C++.

Each folder contains one example or pattern with source code and a short README for easy learning.

## Repository Structure

```text
System Design/
+-- AnimalManagement/
+-- AtmCard/
+-- BankManagement/
+-- DRY/
+-- EmployeeManagement/
+-- ObserverDesignPattern/
+-- SimpleFactory/
+-- Singleton/
+-- Solid/
+-- VehicleManagement/
+-- README.md
+-- .gitignore
```

## Current Examples

- `AnimalManagement/` - abstract classes and polymorphism for animals
- `AtmCard/` - ATM card authentication and account operations
- `BankManagement/` - basic bank account and customer relationship design
- `DRY/` - demonstration of the DRY principle
- `EmployeeManagement/` - abstract employee structure and polymorphism
- `ObserverDesignPattern/` - observer pattern examples
- `SimpleFactory/` - factory patterns and object creation
- `Singleton/` - singleton design pattern example
- `Solid/` - SOLID principle examples
- `VehicleManagement/` - vehicle factory design pattern

## How to Use

1. Open a folder in your C++ IDE or terminal.
2. Compile the `.cpp` file in that folder with a C++ compiler.
3. Run the generated executable.

Example with `g++`:

```powershell
cd "System Design\BankManagement"
g++ -std=c++17 -Wall -Wextra bank_management.cpp -o bank_management.exe
./bank_management.exe
```

## Goals

- Keep each problem in its own folder
- Include short notes for each example
- Use clear and consistent file names
- Avoid storing compiled binaries in Git

## Notes

This repository is a learning workspace. The examples are kept small so they are easy to study and extend later.
