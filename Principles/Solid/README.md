# SOLID Principles

## What does design mean?

Design is the way we structure software so it stays understandable, maintainable, and flexible. Good design makes it easier to change the code without breaking existing behavior.

We use design to:

- keep responsibilities clear
- reduce code duplication
- improve testability
- make future changes easier
- avoid tightly coupled code

## What are SOLID principles?

SOLID is a group of five design principles that help build better object-oriented software. These principles are useful when designing clean class structures and interfaces.

This folder contains examples for:

- `single_responsibility.cpp` - Single Responsibility Principle
- `open_closed.cpp` - Open/Closed Principle
- `liskov_substitution.cpp` - Liskov Substitution Principle
- `interface_segregation.cpp` - Interface Segregation Principle
- `dependency_inversion.cpp` - Dependency Inversion Principle

## Why they matter

Without these principles, code tends to become:

- difficult to maintain
- hard to test
- too tightly coupled
- hard to extend
- fragile when new features are added

## Important notes

- Each principle solves a different design problem.
- Together they create more stable and scalable systems.
- They are especially useful in larger codebases.
- They help reduce the risk of breaking old behavior while adding new features.

## 1. Single Responsibility Principle (SRP)

A class should have only one reason to change.

**Meaning:** one class should focus on one responsibility.

**Why it matters:**
- easier to understand
- easier to test
- less accidental coupling

**Bad design:** one class handles user logic, database logic, and printing logic at the same time.

## 2. Open/Closed Principle (OCP)

Software entities should be open for extension but closed for modification.

**Meaning:** add new behavior without changing the existing working code.

**Why it matters:**
- safer updates
- easier feature extension
- less risk of breaking old code

## 3. Liskov Substitution Principle (LSP)

Objects of a base class should be replaceable with objects of a derived class without changing the correctness of the program.

**Meaning:** subclasses should honor the behavior of the parent type.

**Why it matters:**
- prevents incorrect inheritance use
- keeps polymorphism reliable
- reduces hidden bugs

## 4. Interface Segregation Principle (ISP)

Clients should not be forced to depend on interfaces they do not use.

**Meaning:** split large interfaces into smaller, focused ones.

**Why it matters:**
- less unnecessary dependency
- cleaner code
- better maintainability

## 5. Dependency Inversion Principle (DIP)

High-level modules should not depend on low-level modules. Both should depend on abstractions.

**Meaning:** depend on interfaces or abstract classes instead of concrete implementations.

**Why it matters:**
- reduces coupling
- easier to change implementation details
- improves flexibility and testing

## When to use SOLID

Use SOLID when:

- your project is growing
- multiple classes work together closely
- new features are being added frequently
- you want maintainable and scalable architecture

## Advantages

- cleaner design
- easier code maintenance
- better extensibility
- easier testing and debugging
- more reusable components

## Disadvantages

- may feel too abstract for small programs
- can add extra classes and interfaces
- may be over-engineering if the project is tiny

## How to run

Compile any relevant file from this folder:

```powershell
cd "System Design\Principles\Solid"
g++ -std=c++17 -Wall -Wextra single_responsibility.cpp -o srp.exe
./srp.exe
```

You can replace the file name with `open_closed.cpp`, `liskov_substitution.cpp`, `interface_segregation.cpp`, or `dependency_inversion.cpp`.

## Simple summary

SOLID principles are design rules that help us build cleaner, more flexible, and more maintainable software. They are especially valuable when building larger systems that must be extended over time.
