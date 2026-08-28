# Structural Design Patterns

Structural design patterns focus on how classes and objects are connected. They help make relationships between objects more flexible without forcing large changes in existing code.

## Recommended Order

1. [Adapter](Adapter/README.md)
2. Bridge
3. Composite
4. Decorator
5. Facade
6. Flyweight
7. Proxy

## Patterns In This Folder

| Pattern | Main Idea | Folder |
|---|---|---|
| Adapter | Make an incompatible class work with the interface expected by the client. | [Adapter](Adapter/README.md) |

Other structural patterns are still to be added: Bridge, Composite, Decorator, Facade, Flyweight, and Proxy.

## What To Learn

- how to connect old code with new code
- how wrapper classes reduce direct dependency
- how clients can depend on clean abstractions
- how object composition can solve interface mismatch

## How To Run

Move into a pattern folder and compile the example you want:

```powershell
g++ -std=c++17 -Wall -Wextra file_name.cpp -o file_name.exe
./file_name.exe
```
