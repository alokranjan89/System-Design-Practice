# Behavioral Design Patterns

Behavioral patterns focus on how objects communicate, delegate work, and change behavior at runtime.

## Recommended Order

1. [Strategy](StrategyDesignPattern/README.md)
2. [Observer](ObserverDesignPattern/README.md)
3. [Iterator](Iterator-design-pattern/README.md)
4. [Command](command-design-pattern/README.md)
5. [Mediator](Mediator-design-pattern/README.md)
6. [State](state-design-pattern/README.md)

## Patterns In This Folder

| Pattern | Main Idea | Folder |
|---|---|---|
| Strategy | Choose interchangeable behavior at runtime | [StrategyDesignPattern](StrategyDesignPattern/README.md) |
| Observer | Notify many objects when one object changes | [ObserverDesignPattern](ObserverDesignPattern/README.md) |
| Iterator | Traverse a collection without exposing internals | [Iterator-design-pattern](Iterator-design-pattern/README.md) |
| Command | Turn a request/action into an object | [command-design-pattern](command-design-pattern/README.md) |
| Mediator | Centralize communication between multiple objects | [Mediator-design-pattern](Mediator-design-pattern/README.md) |
| State | Change behavior when internal state changes | [state-design-pattern](state-design-pattern/README.md) |

## What To Learn

- how objects communicate without tight coupling
- how interfaces allow runtime flexibility
- how one object can delegate behavior to another
- how to keep responsibilities small and clear

## How To Run

Move into a pattern folder and compile the example you want:

```powershell
g++ -std=c++17 -Wall -Wextra file_name.cpp -o file_name.exe
./file_name.exe
```

Some folders contain multiple examples. In those folders, read the local README first.
