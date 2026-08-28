# Prototype Design Pattern

## What is the Prototype pattern?

The Prototype pattern creates new objects by copying an existing object instead of constructing a new one from scratch.

This is useful when creating an object is expensive or when many objects need the same initial configuration.

## Problem it solves

Sometimes creating an object from zero requires a lot of effort, setup, or costly initialization. A direct constructor may also repeat similar configuration logic in many places.

This pattern solves that by allowing an existing object to act as a template.

## Key idea

A prototype object is cloned to produce new objects with the same state. The new object can then be customized if needed.

## Important notes

- The clone method is the core of the pattern.
- It helps avoid code duplication for object setup.
- It is useful when object creation is expensive or complex.
- Shallow copy and deep copy matter when objects contain nested data.
- Improper cloning can cause shared references and unexpected side effects.

## When to use

Use Prototype when:

- object creation is costly
- objects have similar initial states
- many objects need to be created with the same setup
- you want to avoid repeating configuration logic
- classes are chosen at runtime and cloning is easier than creating from scratch

## Advantages

- reduces repeated setup logic
- faster creation of similar objects
- good for dynamic object creation
- keeps creation logic reusable

## Disadvantages

- cloning logic must be implemented carefully
- deep copy issues can be tricky
- may be overkill for simple object creation

## Real-world examples

- copying a configured product in a manufacturing system
- creating multiple users with the same initial profile data
- duplicating template documents or settings
- creating many similar objects in game development

## Easy Notes For Revision

**Simple idea:** create a new object by copying an existing object.

**Example:** create one configured `Document` object, then clone it whenever a new similar document is needed.

**Where to use:**
- when object creation is expensive
- when many objects have the same initial setup
- when runtime configuration should be copied
- when creating from scratch repeats too much setup logic

**Advantages:**
- avoids repeated initialization
- can be faster than creating from scratch
- makes it easy to create similar objects
- useful when exact object type is known only at runtime

**Disadvantages:**
- cloning logic can be tricky
- deep copy vs shallow copy must be handled carefully
- copied objects may accidentally share mutable data

**Interview explanation:** Prototype creates objects by cloning existing instances. It is useful when creating a fresh object is costly or when many objects share a similar starting state.

## In this folder

The `prototype.cpp` example demonstrates cloning an existing object to produce new ones.

## How to run

```powershell
cd "System Design\DesignPatterns\Creational\Prototype"
g++ -std=c++17 -Wall -Wextra prototype.cpp -o prototype.exe
./prototype.exe
```

## Simple summary

The Prototype pattern is useful when creating objects from scratch is expensive or repetitive. It allows a ready-made instance to be cloned and reused, which saves time and keeps the code cleaner.
