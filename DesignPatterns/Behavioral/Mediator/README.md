# Mediator

Mediator moves coordination between several objects into a central object. Colleagues communicate through the mediator instead of holding direct references to one another.

## Examples

| File | Example |
|---|---|
| [`mediator.cpp`](mediator.cpp) | Chat room forwards messages to other users |
| [`airport.cpp`](airport.cpp) | Airport control tower coordinates aircraft |

Trace `main()` to see the client construct the mediator and colleagues, then see a colleague request coordination through it.

## When it helps

Use Mediator when direct connections between many objects make coordination hard to change. The mediator itself can become a large, hidden dependency, so keep its responsibilities focused. For one or two straightforward interactions, direct calls are clearer.

## Build

From this directory, compile one file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra mediator.cpp -o mediator.exe
.\mediator.exe
```

Substitute `airport.cpp` for the airport example.
