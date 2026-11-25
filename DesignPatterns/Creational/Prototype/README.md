# Prototype

Prototype creates a new object by copying an existing configured object. It is useful when starting from a template is clearer than repeating setup, or when the concrete type is only known at runtime.

## Examples

| File | Focus |
|---|---|
| [`prototype.cpp`](prototype.cpp) | Cloneable prototype example |
| [`game.cpp`](game.cpp) | Game-related example |

Trace how each example copies an existing object and then uses the copy. If objects own mutable nested data, check whether the copy is shallow or deep; accidental sharing can cause changes to affect both objects.

## Trade-off

Cloning can centralize repeated setup, but copy semantics can be subtle and cloning may be unnecessary when construction is already simple. The source examples are learning exercises; review their ownership and copy behavior before reusing the approach in a larger program.

## Build

From this directory, compile one file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra prototype.cpp -o prototype.exe
.\prototype.exe
```

Substitute `game.cpp` for the other example.
