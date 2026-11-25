# C++ Low-Level Design Practice

A C++ learning repository for object-oriented programming, design principles, design patterns, and low-level design examples. The examples are small exercises for learning and discussion, not production-ready systems.

## Start here

New to the repository? Follow this path:

1. [OOP fundamentals](OOP/README.md)
2. [Design principles](Principles/README.md)
3. [Design patterns](DesignPatterns/README.md)
4. [LLD practice examples](Examples/README.md)

Each topic guide explains the problem, the main classes or roles, and links to the source files. Read the guide, trace the flow from `main()`, then run the example.

## What's included

| Area | Contents |
|---|---|
| [OOP](OOP/README.md) | Encapsulation, abstraction, inheritance, and polymorphism |
| [Principles](Principles/README.md) | SOLID, DRY, KISS, and YAGNI |
| [Design patterns](DesignPatterns/README.md) | Creational, structural, and behavioral examples |
| [LLD examples](Examples/README.md) | Small domain exercises such as banking, parking, and library management |

## Naming

Folders use PascalCase, C++ source files use lower snake_case, and directory guides use `README.md`.

## Build an example

Compile one `.cpp` file at a time from its directory. For example:

```powershell
cd Examples\BankManagement
g++ -std=c++17 -Wall -Wextra bank_management.cpp -o bank_management.exe
.\bank_management.exe
```

Use the same command with the source filename shown in the relevant README. Some folders contain multiple independent examples. Generated binaries and object files should not be committed.

## How to study a design

- What problem or change does this design address?
- Which class owns each responsibility?
- How do objects collaborate, starting from `main()`?
- What becomes easier to change, and what extra complexity does the design add?

This repository focuses on low-level design. High-level system design topics such as distributed storage, queues, caching, and load balancing are outside its current scope.
