# Singleton

Singleton restricts a class to one shared instance and provides a global access point. This can be useful for a truly shared resource, but also creates hidden global state and makes dependencies and tests harder to manage. Prefer passing a dependency explicitly when that is practical.

## Examples in this folder

| File | Focus |
|---|---|
| [`singleton.cpp`](singleton.cpp) | Basic Singleton example |
| [`singleton_variants.cpp`](singleton_variants.cpp) | Additional implementation example |
| [`logger.cpp`](logger.cpp) | Logger use case |

There is also a standalone [`singleton_example.cpp`](singleton_example.cpp) Singleton example at the repository root.

Read each source file's implementation before choosing it as a model. In modern C++, a function-local static is usually the simplest thread-safe initialization approach:

```cpp
static Logger& instance() {
    static Logger logger;
    return logger;
}
```

The one-instance property does not make a class thread-safe overall, and a Singleton remains global state. Avoid adding one just to avoid passing an object around.

## Build

From this directory, compile one file at a time. For example:

```powershell
g++ -std=c++17 -Wall -Wextra singleton.cpp -o singleton.exe
.\singleton.exe
```
