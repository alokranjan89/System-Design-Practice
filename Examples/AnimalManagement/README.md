# Animal Management

This example demonstrates abstract classes and polymorphism using animals.

## Key Concepts

- Abstract base class `Animal`
- Concrete subclasses `Dog` and `Cat`
- Polymorphic behavior through `makeSound()`
- `Owner` stores adopted animals and calls behavior through `Animal*`
- Manual cleanup with `delete`

## Main Classes

| Class | Responsibility |
|---|---|
| `Animal` | Base class with common animal data and shared behavior |
| `Dog` | Concrete animal that implements `makeSound()` by barking |
| `Cat` | Concrete animal that implements `makeSound()` by meowing |
| `Owner` | Keeps a list of adopted animals and shows their behavior |

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\AnimalManagement"
g++ -std=c++17 -Wall -Wextra animal_management.cpp -o animal_management.exe
./animal_management.exe
```
