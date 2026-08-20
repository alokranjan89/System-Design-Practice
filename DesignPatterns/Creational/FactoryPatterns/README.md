# Factory Patterns

Factory patterns are creational patterns that move object creation logic away from client code.

Instead of writing `new Car()` or `new Bike()` everywhere, the client asks a factory to create the correct object.

## Recommended Order

1. [simple_factory.cpp](simple_factory.cpp)
2. [factory_method.cpp](factory_method.cpp)
3. [abstract_factory.cpp](abstract_factory.cpp)
4. [FACTORY_METHOD_QUICK_REFERENCE.md](FACTORY_METHOD_QUICK_REFERENCE.md)

## Why Factories Are Useful

Factories help when:

- object creation has conditions
- client code should not depend directly on concrete classes
- many related object types exist
- object creation may change later
- you want cleaner and more maintainable code

## Simple Factory

**File:** [simple_factory.cpp](simple_factory.cpp)

Simple Factory keeps all creation logic in one factory method.

Use it when:

- the project is small
- there are only a few object types
- creation logic is simple

Main trade-off:

- easy to understand, but adding a new type usually means modifying the factory method

## Factory Method

**File:** [factory_method.cpp](factory_method.cpp)

Factory Method defines a common factory interface, then lets child factory classes decide which object to create.

Use it when:

- new product types may be added later
- each product should have its own creation class
- you want better Open/Closed Principle support

Main trade-off:

- more flexible than Simple Factory, but creates more classes

## Abstract Factory

**File:** [abstract_factory.cpp](abstract_factory.cpp)

Abstract Factory creates families of related objects.

Example from this folder:

- `WindowsFactory` creates Windows button and Windows checkbox
- `MacFactory` creates Mac button and Mac checkbox

Use it when:

- related objects must be created together
- products belong to families or themes
- the client should not know concrete product classes

Main trade-off:

- powerful for product families, but heavier than the other factory styles

## Quick Comparison

| Pattern | Main Idea | Best For |
|---|---|---|
| Simple Factory | One factory method chooses the object | Small/simple creation logic |
| Factory Method | One factory class per product type | Extensible product creation |
| Abstract Factory | One factory creates a family of products | Related product families |

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra simple_factory.cpp -o simple_factory.exe
./simple_factory.exe
```

Replace `simple_factory.cpp` with `factory_method.cpp` or `abstract_factory.cpp` to run the other examples.

## Simple Summary

Use factories when you want client code to ask for objects instead of directly creating concrete classes. Start with Simple Factory, then learn Factory Method, then Abstract Factory.
