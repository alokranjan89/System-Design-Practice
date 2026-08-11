# Factory Patterns

Factory patterns centralize object creation so client code does not directly depend on concrete classes.

## Files

- `simple_factory.cpp` - one factory method decides which object to create.
- `factory_method.cpp` - subclasses decide which concrete product to create.
- `abstract_factory.cpp` - creates families of related objects.

## What to learn

- How to hide object creation behind a common interface.
- How each factory style reduces direct `new` usage in client code.
- When extra abstraction helps and when it may be unnecessary.

## Advantages

- Keeps object creation logic in one place.
- Makes client code depend less on concrete classes.
- Makes adding new product types easier in many designs.

## Disadvantages

- Adds more classes and interfaces.
- Can make simple programs harder to read if overused.
- Factory changes may still be needed when adding new types, depending on the pattern.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\FactoryPatterns"
g++ -std=c++17 -Wall -Wextra simple_factory.cpp -o simple_factory.exe
./simple_factory.exe
```

You can compile `factory_method.cpp` or `abstract_factory.cpp` the same way.
