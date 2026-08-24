# Singleton Design Pattern

## What does design mean?

Design is the process of creating a clear structure for a system so that it is easier to maintain and reason about. In software, design decides how objects are created, shared, and accessed.

We use design when we need to:

- manage shared resources
- control repeated object creation
- keep access points clear and consistent
- reduce accidental duplication
- build stable application-wide configuration

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

## Advantages

- ensures one shared instance
- easy to access globally
- avoids unnecessary duplicate objects
- useful for shared system resources

## Disadvantages

- global state can make debugging harder
- can reduce code flexibility
- may hurt testability
- overuse can create hidden dependencies

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

## Eager initialization example

This version creates the object at startup.

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

### Advantages

- simple and easy to understand
- object exists before first use
- no lock is needed

### Disadvantages

- object is created even if it is never used
- may be wasteful for expensive resources

## Lazy initialization example

This version creates the object only when it is needed.

```cpp
class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() {}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
```

### Advantages

- object is created only when needed
- better for expensive initialization
- useful in multithreaded code

### Disadvantages

- more complex than eager initialization
- thread-safety has to be managed carefully

## Best practice note

In modern C++, a function-local static variable is often the simplest and safest way to implement a Singleton. It is easier to manage and avoids manual memory cleanup in many cases.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Singleton"
g++ -std=c++17 -Wall -Wextra singleton.cpp -o singleton.exe
./singleton.exe
```

## Simple summary

The Singleton pattern is used when exactly one shared instance should exist throughout the application. It helps enforce consistency and avoid unnecessary duplication, but it should be used carefully because it introduces global state.
