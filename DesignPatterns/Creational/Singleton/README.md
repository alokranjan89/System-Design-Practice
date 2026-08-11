# Singleton Design Pattern

The Singleton pattern ensures that a class has only one object and provides a common access point to that object.

## Current example

`singleton.cpp` uses eager initialization with a static pointer.

## Method 1: Eager initialization

### Steps

1. Make the constructor private.
2. Create one static pointer inside the class.
3. Initialize the object before `main()` starts.
4. Return the same object from `getInstance()`.
5. Compare two returned pointers to prove both point to the same object.

### Code idea

```cpp
class Singleton
{
private:
    static Singleton *instance;

    Singleton() {}

public:
    static Singleton *getInstance()
    {
        return instance;
    }
};

Singleton *Singleton::instance = new Singleton();
```

### Advantages

- Simple to understand.
- No mutex is required.
- Object is ready before first use.

### Disadvantages

- Object is created even if it is never used.
- Uses `new`, so cleanup must be considered in larger programs.
- Startup can become heavier if construction is expensive.

## Method 2: Lazy initialization with mutex

### Steps

1. Make the constructor private.
2. Keep a static pointer initialized with `nullptr`.
3. When `getInstance()` is called, check whether the object exists.
4. Lock a mutex before creating the object.
5. Check again after locking.
6. Create the object only once.
7. Return the same pointer every time.

### Code idea

```cpp
class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;

    Singleton() {}

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);

            if (instance == nullptr)
            {
                instance = new Singleton();
            }
        }

        return instance;
    }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;
```

### Advantages

- Object is created only when needed.
- Mutex protects object creation in multithreaded code.
- Useful when object construction is expensive.

### Disadvantages

- More complex than eager initialization.
- Uses `new`, so cleanup must be handled carefully.
- Incorrect locking can cause thread-safety bugs.

## Important notes

- Singletons introduce global state, so use them carefully.
- Prefer dependency injection when testability is important.
- In modern C++, a function-local static object is often the simplest thread-safe Singleton approach.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall -Wextra singleton.cpp -o singleton.exe
./singleton.exe
```
