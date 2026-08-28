# Creational Design Patterns

Creational design patterns focus on object creation. This folder is only an index for the creational pattern notes.

## Recommended Order

1. [Factory Patterns](FactoryPatterns/README.md)
2. [Builder](Builder/README.md)
3. [Prototype](Prototype/README.md)
4. [Singleton](Singleton/README.md)

## Patterns In This Folder

| Pattern | Main Idea | Folder |
|---|---|---|
| Factory Patterns | Move object creation away from client code. | [FactoryPatterns](FactoryPatterns/README.md) |
| Builder | Build complex objects step by step. | [Builder](Builder/README.md) |
| Prototype | Create objects by cloning existing objects. | [Prototype](Prototype/README.md) |
| Singleton | Ensure only one shared instance exists. | [Singleton](Singleton/README.md) |

## How To Use This Folder

Open one pattern folder at a time. Read that pattern's README, then compile and run its `.cpp` example.

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Creational\Builder"
g++ -std=c++17 -Wall -Wextra builder.cpp -o builder.exe
./builder.exe
```
