# Builder

Builder assembles an object through clear construction steps. It can make creation easier to read when an object has many optional settings or multiple valid configurations.

## Examples

| File | Example |
|---|---|
| [`builder.cpp`](builder.cpp) | Computer configuration |
| [`pizza.cpp`](pizza.cpp) | Pizza with optional toppings |

Look for the product, builder, and final `build()` call. Trace which values are set and whether required values can be omitted.

## When it helps

Use Builder when a long constructor or many constructor overloads make object creation confusing. For a small object with a few required values, a regular constructor is usually clearer. The pattern adds builder code, and `build()` should ensure required fields are valid.

## Build

Run from this directory, one source file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra builder.cpp -o builder.exe
.\builder.exe
```

Substitute `pizza.cpp` to run the pizza example.
