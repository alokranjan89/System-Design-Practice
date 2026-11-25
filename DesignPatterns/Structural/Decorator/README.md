# Decorator

Decorator adds behavior to an object by wrapping it in another object that implements the same interface. Wrappers can be combined at runtime, so optional features do not need a separate subclass for every combination.

## Roles in `mario.cpp`

| Role | Class | Responsibility |
|---|---|---|
| Component | `Character` | Common interface for the base object and wrappers |
| Concrete component | `Mario` | Base character |
| Decorator | `CharacterDecorator` | Holds and delegates to another `Character` |
| Concrete decorators | `HeightUp`, `GunPowerUp`, `StarPowerUp` | Add an ability to the wrapped character |

Follow `main()` as it wraps Mario with each power-up. Each decorator keeps the `Character` interface and builds on the wrapped object's abilities.

Use this when optional behavior should be composed at runtime. It adds wrapper objects and can make deeply nested combinations harder to inspect.

## Build

Run from this directory:

```powershell
g++ -std=c++17 -Wall -Wextra mario.cpp -o mario.exe
.\mario.exe
```
