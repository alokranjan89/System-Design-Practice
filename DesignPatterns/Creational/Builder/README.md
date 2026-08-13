# Builder Design Pattern

## What does design mean?

Design means planning how a system should be structured so that it stays simple, clear, and maintainable. In software, design decides how objects are built and how responsibilities are assigned.

We use design when we want to:

- avoid messy construction logic
- make code readable
- manage complex object creation cleanly
- reduce constructor overload issues
- support different configurations without rewriting logic

## What is the Builder pattern?

The Builder pattern is used to construct a complex object step by step. Instead of passing a huge list of parameters to a constructor, we use a builder object that sets one part at a time and finally creates the final object.

This pattern is very useful when objects have many optional fields or many configuration combinations.

## Problem it solves

When a class has many optional attributes, creating it directly becomes difficult because the constructor may need many arguments. This leads to:

- long parameter lists
- confusing constructor calls
- fragile object creation logic
- many overloaded constructors

The Builder pattern solves this by separating object construction from the final object representation.

## Key idea

Create a builder class that stores the object being built and provides methods like `setCPU()`, `setRAM()`, and `setGPU()`. At the end, call `build()` to return the final object.

This provides a fluent and readable way to construct complex objects.

## Important notes

- The product is the final object being created.
- The builder encapsulates the construction steps.
- A fluent interface allows method chaining.
- The builder hides complex initialization details.
- It is easier to create different variants of the same object.
- It helps when object creation is not a single simple assignment.

## When to use

Use Builder when:

- the object has many optional fields
- the constructor becomes too long
- you need to create objects in multiple steps
- different object configurations are common
- you want readable object creation code

## Advantages

- cleaner object construction
- easier to understand than long constructors
- supports many configurations
- improves maintainability
- separates construction logic from the object itself

## Disadvantages

- adds extra classes
- may be unnecessary for small objects
- can be more code than a simple constructor

## Real-world example

Think about creating a computer configuration:

- CPU
- RAM
- SSD
- GPU
- Wi-Fi
- RGB

Instead of passing all these values in one constructor, the builder assembles them one by one.

## In this folder

The example in `builder.cpp` demonstrates a `Computer` object being created through a `ComputerBuilder`.

## Example walkthrough

1. Create a builder.
2. Set the required properties.
3. Chain method calls.
4. Call `build()`.
5. Get the final built object.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Builder"
g++ -std=c++17 -Wall -Wextra builder.cpp -o builder.exe
./builder.exe
```

## Simple summary

The Builder pattern is used when an object has many parts or optional settings. It makes creation readable, modular, and easy to customize without creating huge constructors.
