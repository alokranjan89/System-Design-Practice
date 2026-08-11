# Singleton Design Pattern

The Singleton pattern ensures a class has only one instance and provides a global point of access to it.

## What this example shows

- A private constructor prevents direct creation of `Singleton` objects.
- A static pointer `instance` stores the single created object.
- `getInstance()` lazily initializes the object on first request and returns the same instance thereafter.
- All callers receive the same address, proving only one instance exists.

## When to use

- When exactly one instance of a class is required.
- When the same shared resource must be accessed globally.
- When a single coordinating object is needed, such as configuration managers, logging components, or cache controllers.

## Important notes

- Singletons introduce global state, which can make code harder to test and reason about.
- Prefer dependency injection when shared behavior is needed for testing or future flexibility.
- In multithreaded code, guard lazy initialization with a mutex or use a thread-safe static local variable.

## Example behavior in `singleton.cpp`

- `Singleton::instance` is initialized to `nullptr`.
- The first call to `Singleton::getInstance()` creates the object.
- Subsequent calls return the same pointer.
- The example prints the same memory address for `s1`, `s2`, and `s3`.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall singleton.cpp -o singleton.exe
./singleton.exe
```

## Pros and cons

### Pros
- Controlled access to a single shared instance.
- Lazy initialization delays creation until needed.
- Useful for centralized services and shared configuration.

### Cons
- Hidden global state can reduce modularity.
- Can be difficult to test and mock.
- Needs careful handling in concurrent environments.
