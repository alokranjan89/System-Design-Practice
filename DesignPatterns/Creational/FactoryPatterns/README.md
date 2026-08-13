# Factory Patterns

## What does design mean?

Design is the planning of how classes and objects should interact to keep the system flexible and maintainable. In software, good design helps organize logic so the code becomes easier to extend and less dependent on details.

We use design when we want to:

- reduce coupling
- separate responsibility from object creation
- make code easier to extend
- avoid repeated `new` logic in many places
- keep the client code cleaner

## What are factory patterns?

Factory patterns are used to create objects without exposing the logic of how they are constructed. Instead of directly creating concrete classes, the client works through a factory.

This helps when the creation logic may change over time or when different object types need to be created based on conditions.

## Problem it solves

If object creation is written directly in many places, the code becomes difficult to maintain. Every time a new product type is introduced, multiple places may need to be changed.

This creates:

- repeated creation logic
- tight coupling to concrete classes
- difficult maintenance when product types grow
- code that is harder to extend without breaking others

## Key idea

Instead of the client creating objects directly, a factory decides which object to instantiate. The client only asks for the object and works with the common interface.

## Important notes

- Factory patterns hide construction details.
- Client code depends on abstraction, not concrete classes.
- They improve flexibility and scalability.
- They are useful when object creation rules may vary.
- The right type of factory depends on the complexity of the problem.

## Types in this folder

### Simple Factory

Simple Factory has one factory method that decides which object to create.

**Use it when:**
- creation logic is simple
- you want one central place to manage object creation
- the system is not too complex

**Advantages:**
- easy to understand
- reduces scattered `new` statements
- useful for small/medium systems

**Disadvantages:**
- not as extensible as other factory patterns
- can become a large conditional block if too many types are added

### Factory Method

Factory Method delegates object creation to subclasses.

**Use it when:**
- a class cannot decide which concrete product to create
- new product types may be added later
- subclass logic should decide the object type

**Advantages:**
- better extension support
- keeps creation logic in a separate layer
- good for polymorphism

**Disadvantages:**
- more classes and abstraction
- can be more complex than a simple factory

### Abstract Factory

Abstract Factory creates related objects as a family.

**Use it when:**
- product objects must work together
- there are multiple variants of a family
- you need consistent object creation across a platform or theme

**Advantages:**
- good for object families
- supports consistent product sets
- reduces incompatible combinations

**Disadvantages:**
- more complex to design
- can be overkill for simple programs

## When to use

Use factory patterns when:

- object creation logic must be centralized
- the client should not depend on concrete classes
- different products may be created under different conditions
- the system may expand with new product types later

## Real-world examples

- creating different payment methods in an app
- generating different vehicle types based on user input
- creating different UI themes for mobile or desktop apps
- manufacturing different product families based on region or configuration

## In this folder

- `simple_factory.cpp` uses one factory to create a product
- `factory_method.cpp` uses subclass-level creation decisions
- `abstract_factory.cpp` creates consistent related objects

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra simple_factory.cpp -o simple_factory.exe
./simple_factory.exe
```

Compile `factory_method.cpp` or `abstract_factory.cpp` in the same folder using the same command pattern.

## Simple summary

Factory patterns help create objects without letting the client know the exact class being created. They make the code cleaner, easier to extend, and less dependent on concrete implementations.
