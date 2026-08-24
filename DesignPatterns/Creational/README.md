# Creational Design Patterns

## What does design mean?

Design is the planning of how software components will be built, structured, and connected. Good design makes the system easier to understand, maintain, and extend. In software, design is not only about writing code; it is about choosing the right structure before implementation.

We use design when we want to:

- reduce complexity
- avoid code duplication
- keep responsibilities clear
- make future changes easier
- create reusable and testable code

## What are creational design patterns?

Creational design patterns focus on how objects are created. They help manage object creation logic so that code does not become tightly coupled to specific classes or repetitive across the project.

These patterns are useful when:

- object creation is complex
- we want to centralize creation logic
- we need many objects with similar setup
- we want to hide construction details
- we need only one shared object or cloneable object instances

## Recommended order

1. [Factory Patterns](FactoryPatterns/README.md)
2. [Builder](Builder/README.md)
3. [Prototype](Prototype/README.md)
4. [Singleton](Singleton/README.md)

## This folder includes

- [FactoryPatterns](FactoryPatterns/README.md) - object creation through factories
- [Builder](Builder/README.md) - step-by-step construction of complex objects
- [Prototype](Prototype/README.md) - object cloning
- [Singleton](Singleton/README.md) - single-instance creation control

## Problem these patterns solve

Without proper object creation design, code becomes messy because:

- object creation logic is repeated everywhere
- client code depends directly on concrete classes
- new object types require changing many places
- constructing complex objects becomes hard to read
- global state and duplicate instances may appear accidentally

## Important notes

- Creational patterns help control the creation process of objects.
- They reduce direct dependency on concrete classes.
- They improve code flexibility and maintainability.
- They can hide creation decisions behind a simpler interface.
- The right pattern depends on the problem: create a new object, decide based on type, clone an existing object, or enforce one instance.

## Pattern summaries

### Simple Factory

Simple Factory is a way to centralize object creation in one class or method. The client asks the factory for an object instead of creating it manually.

**Key idea:** one place decides which concrete class to create.

**When to use:**
- when object creation is repetitive
- when the choice is based on simple conditions
- when you want to avoid scattered `new` operations

**Important notes:**
- easy to understand and implement
- not as flexible as Factory Method
- useful for small systems where creation logic is straightforward

### Factory Method

Factory Method defines an interface for creating an object, while subclasses decide which concrete object will be created.

**Key idea:** object creation is delegated to subclasses.

**When to use:**
- when a class cannot know which object it must create
- when new product types may be added later
- when creation logic should be extended without changing the main code

**Important notes:**
- improves extensibility
- good for open/closed design
- introduces more abstraction than a simple factory

### Abstract Factory

Abstract Factory creates families of related objects without exposing their concrete classes.

**Key idea:** different factories create related objects consistent with a common theme.

**When to use:**
- when objects belong to the same product family
- when UI or platform-specific variants must be created together
- when multiple related products must stay consistent

**Important notes:**
- more powerful than a basic factory
- good for product families
- can be too heavy for simple systems

### Builder

Builder separates complex object construction from the final object representation. It is useful when an object has many optional fields or many configuration steps.

**Key idea:** build the object step by step instead of using a giant constructor.

**When to use:**
- many optional parameters
- large configuration objects
- readable fluent object creation

**Important notes:**
- keeps object creation readable
- improves maintainability
- avoids constructor explosion

### Prototype

Prototype creates new objects by copying an existing object instead of constructing a full new instance from scratch.

**Key idea:** cloning a configured object is faster and easier than rebuilding it.

**When to use:**
- object creation is expensive
- many objects share the same initial setup
- runtime object creation depends on an existing instance

**Important notes:**
- shallow vs deep copy matters
- useful for cloning complex objects
- must be careful about shared mutable references

### Singleton

Singleton ensures that only one instance of a class exists and gives a global access point to it.

**Key idea:** one shared instance throughout the application.

**When to use:**
- configuration manager
- logging service
- database connection manager
- shared global resource

**Important notes:**
- introduces global state
- must be used carefully
- not always the best choice for testability

## Advantages of creational patterns

- cleaner object creation logic
- better separation of concerns
- easier maintenance and extension
- reduces code duplication
- better control over object lifetime and initialization

## Disadvantages

- extra classes and abstraction can add complexity
- some patterns are overkill for small applications
- misuse can create hidden global state or poor design decisions

## How to run the examples

Compile and run one example at a time.

```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra simple_factory.cpp -o simple_factory.exe
./simple_factory.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra factory_method.cpp -o factory_method.exe
./factory_method.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra abstract_factory.cpp -o abstract_factory.exe
./abstract_factory.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\Builder"
g++ -std=c++17 -Wall -Wextra builder.cpp -o builder.exe
./builder.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\Builder"
g++ -std=c++17 -Wall -Wextra pizza.cpp -o pizza.exe
./pizza.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall -Wextra singleton.cpp -o singleton.exe
./singleton.exe
```

```powershell
cd "System Design\DesignPatterns\Creational\Prototype"
g++ -std=c++17 -Wall -Wextra prototype.cpp -o prototype.exe
./prototype.exe
```

## Simple summary

Creational patterns are about how objects are created in a clean, controlled, and maintainable way. They help us choose the right creation strategy depending on the problem: one instance, multiple related objects, cloning, or step-by-step construction.
