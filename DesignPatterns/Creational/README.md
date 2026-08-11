# Creational Design Patterns

This folder contains creational design pattern examples and one central guide.
All information about these patterns is kept in this single `README.md`.

## Folder Structure

- `FactoryPatterns/`
  - `simple_factory.cpp`
  - `factory_method.cpp`
  - `abstract_factory.cpp`
- `Prototype/`
  - `prototype.cpp`
- `Singleton/`
  - `singleton.cpp`

## What This Folder Shows

Creational patterns are about how objects are created. These examples demonstrate:

- `Simple Factory` - a single place decides which object to create.
- `Factory Method` - subclasses decide which concrete object to instantiate.
- `Abstract Factory` - create families of related objects without specifying concrete classes.
- `Prototype` - create objects by cloning an existing object.
- `Singleton` - ensure only one shared instance exists.

## Pattern Summaries

### Simple Factory
- Centralizes object creation in one place.
- The client asks a factory for an object by type or configuration.
- Good when you have a small number of concrete classes and want to avoid `new` scattered across code.
- Example in `FactoryPatterns/simple_factory.cpp`.

**Important Notes:**
- Not a formal GOF pattern, but very useful in practice.
- This pattern still exposes a single factory method, so avoid putting business logic inside it.
- Use it when object creation rules are simple and likely to change.

### Factory Method
- Defines an interface for creating objects, with subclasses deciding which product to create.
- Use when a class cannot anticipate the exact type of object it must create.
- Example in `FactoryPatterns/factory_method.cpp`.

**Important Notes:**
- The client works with the factory interface, not concrete classes.
- This pattern adds a layer of indirection, so use it when extension is expected.
- It is ideal when each product type requires a separate creation process.

### Abstract Factory
- Provides an interface for creating families of related objects.
- Useful when products should be used together and come from the same variant.
- Example in `FactoryPatterns/abstract_factory.cpp`.

**Important Notes:**
- Use when objects must come from the same family, such as UI widgets for one platform.
- Keep the factory interface stable, and let concrete factories implement the details.
- Avoid overusing this pattern for unrelated object creation.

### Singleton
- Ensures a class has only one instance and provides a global access point.
- Use carefully, because singletons can introduce hidden global state.
- Example in `Singleton/singleton.cpp`.

**Important Notes:**
- Singletons are not just "global variables in disguise"; they control instance creation.
- Ensure thread safety when you use lazy initialization in C++.
- Prefer dependency injection if the singleton behavior is only needed for testing convenience.

### Prototype
- Creates new objects by copying an existing object.
- Useful when object construction is expensive or when many objects share the same starting state.
- Example in `Prototype/prototype.cpp`.

**Important Notes:**
- Decide whether each clone should use shallow copy or deep copy.
- Avoid sharing mutable internal state accidentally.
- Prefer smart pointers in larger projects to manage cloned object ownership safely.

## When to Use Each Pattern

- **Simple Factory**: when you want one place to create similar objects and reduce `new` usage.
- **Factory Method**: when the class cannot know exactly which concrete object will be needed.
- **Abstract Factory**: when you need to create matching objects from the same product family.
- **Prototype**: when cloning an existing configured object is easier than building from scratch.
- **Singleton**: when a single shared instance should be used globally.

## How to Run the Examples

Compile and run one example at a time.

Example:
```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall simple_factory.cpp -o simple_factory.exe
./simple_factory.exe
```

For Singleton:
```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall singleton.cpp -o singleton.exe
./singleton.exe
```

For Prototype:
```powershell
cd "System Design\DesignPatterns\Creational\Prototype"
g++ -std=c++17 -Wall prototype.cpp -o prototype.exe
./prototype.exe
```

## Notes

- Use the source files in each subfolder to study one pattern at a time.
- Subfolder READMEs contain extra notes for specific examples.
- Keep generated `.exe` files out of Git.
