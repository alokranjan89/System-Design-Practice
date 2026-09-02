# Singleton Design Pattern

## What is the Singleton pattern?

The Singleton pattern ensures that a class has only one instance in the entire application and gives a single global access point to it.

It is useful when a system needs one common object that is shared across multiple components.

## Problem it solves

Without Singleton, a class may be instantiated multiple times, causing repeated objects that do not share the same state. This can lead to:

- duplicate resources
- inconsistent configuration
- wasted memory
- hard-to-manage shared state

## Key idea

The constructor is made private, and a static method returns the same instance every time.

This guarantees that only one object is created and reused throughout the application.

## Important notes

- only one instance is allowed
- global access is provided through a static method
- it is good for shared services like configuration or logging
- it can introduce hidden global state
- it should be used carefully in large systems
- testability can become harder if it is used too much

## When to use

Use Singleton when:

- one shared object is required across the app
- a configuration object must be consistent everywhere
- a resource manager is meant to be shared
- object initialization should happen only once

## General advantages

- ensures that only one shared instance is created
- provides a single access point for shared application state
- avoids duplicate expensive resources
- can coordinate services such as logging, configuration, and caching

## General disadvantages

- introduces global state and hidden dependencies
- makes unit testing and dependency replacement harder
- couples callers to a concrete implementation
- can become a bottleneck if the instance is not designed for concurrency
- lifetime and shutdown behavior may be difficult to control
- overuse can hide poor dependency design

## Common real-world examples

- application configuration manager
- logging service
- database connection manager
- cache manager

## Easy Notes For Revision

**Simple idea:** allow only one object of a class and provide one global access point.

**Example:** a `Logger` should usually have one shared instance so all parts of the application write logs through the same object.

**Where to use:**
- shared configuration
- logging
- cache manager
- connection pool manager
- resource manager that should not be duplicated

**Advantages:**
- guarantees a single shared instance
- avoids duplicate resource objects
- provides simple global access
- useful for application-wide services

**Disadvantages:**
- introduces global state
- can make testing harder
- can hide dependencies
- overuse can make code tightly coupled

**Interview explanation:** Singleton restricts object creation so only one instance exists. It is useful for shared resources, but it should be used carefully because global state can make code harder to test and maintain.

## In this folder

`singleton.cpp` demonstrates how a class can be restricted to one instance with a global access method.

## Implementation methods

The following methods all return the same object, but they differ in when the
object is created, how much synchronization they need, and how much complexity
they introduce.

### 1. Simple lazy initialization

The object is created inside `getInstance()` the first time it is requested.

```cpp
static Singleton* instance = nullptr;

static Singleton* getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}
```

#### Advantages

- creates the object only when it is needed
- simple to read and implement
- avoids startup cost when the object is never used
- suitable for single-threaded programs

#### Disadvantages

- not thread-safe: two threads can create two objects at the same time
- manual `new` requires lifetime and cleanup decisions
- concurrent access can expose a partially initialized object
- should not be used as written in multithreaded production code

### 2. Double-checked locking

The first check avoids locking after initialization. The second check prevents
two threads from creating the object while the lock is held.

```cpp
if (instance == nullptr) {
    lock_guard<mutex> lock(mtx);
    if (instance == nullptr) {
        instance = new Singleton();
    }
}
return instance;
```

#### Advantages

- creates the object only when it is needed
- avoids taking the lock on most calls after initialization
- can be useful when the implementation is carefully synchronized

#### Disadvantages

- more difficult to implement and review correctly
- requires a mutex and additional shared state
- the shown raw-pointer version is not fully safe in portable C++ without
  correct atomic memory ordering
- locking adds complexity and runtime overhead
- the old MinGW 6.3 compiler in this workspace does not provide `std::mutex`,
  so this example does not compile with that toolchain

### 3. Eager initialization

The object is created before `main()` when the static data member is initialized.

```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton();
```

#### Advantages

- simple and easy to understand
- thread-safe during initialization
- no locking is needed in `getInstance()`
- initialization failure happens early, during program startup

#### Disadvantages

- object is created even if it is never used
- startup can be slower
- expensive initialization always consumes resources
- initialization order across different translation units can be difficult
- raw `new` makes ownership and cleanup less clear

### 4. Function-local static initialization (recommended)

Modern C++ guarantees that initialization of a function-local static is
thread-safe. The object is created on first use and destroyed automatically at
program shutdown.

```cpp
static Singleton& getInstance() {
    static Singleton instance;
    return instance;
}
```

#### Advantages

- lazy initialization and thread-safe first construction
- no explicit mutex, raw pointer, or manual cleanup
- supported from C++11 onward
- avoids most static initialization order problems

#### Disadvantages

- the instance usually lives until program shutdown
- destruction order can still matter when other global objects use it
- returning a reference instead of a pointer may require small API changes
- it is still global state and therefore still has testing and coupling costs

## Best practice note

In modern C++, a function-local static variable is often the simplest and safest way to implement a Singleton. It is easier to manage and avoids manual memory cleanup in many cases.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall -Wextra sing.cpp -o sing.exe
./sing.exe
```

## Simple summary

The Singleton pattern is used when exactly one shared instance should exist throughout the application. For most modern C++ code, prefer function-local static initialization. Use eager initialization when startup creation is acceptable, and use explicit locking only when there is a specific need and the synchronization has been designed correctly. The pattern should still be used carefully because it introduces global state.
