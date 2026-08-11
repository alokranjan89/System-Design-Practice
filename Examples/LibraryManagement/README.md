# Library Management System

This example models a small library system using C++ classes.

## What this example shows

- Users can be represented through a base class.
- Students and librarians have different responsibilities.
- Books can be stored and managed by the library.
- Basic OOP concepts can be applied to a real-world problem.

## Concepts used

- Encapsulation
- Inheritance
- Runtime polymorphism
- Class relationships
- Vectors for storing multiple objects

## Learning notes

- Keep user behavior in user-related classes.
- Keep book data inside the `Book` class.
- Keep library-level actions inside the library management class.
- In larger projects, prefer smart pointers instead of raw pointers.

## How to run

```powershell
cd "System Design\Examples\LibraryManagement"
g++ -std=c++17 -Wall -Wextra library.cpp -o library.exe
./library.exe
```
