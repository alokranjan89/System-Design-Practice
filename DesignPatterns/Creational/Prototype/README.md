# Prototype Design Pattern

The Prototype pattern creates new objects by cloning an existing instance, rather than constructing new objects directly.

## What this folder shows

- The pattern is useful when object creation is expensive or complex.
- A prototype object is cloned to produce new objects with the same state.
- Clients can work with the prototype interface and do not need detailed knowledge of concrete classes.

## Key concepts

- Prototype object: the instance that knows how to clone itself.
- Clone operation: typically implemented with a `clone()` or copy method.
- Shallow vs deep copy: use a deep copy when the object contains references to mutable subobjects.

## When to use

- When creating objects directly is costly in time or resources.
- When object configurations are complex and should be duplicated.
- When classes are determined at runtime and new instances should be created quickly.

## Notes

- The pattern decouples object creation from specific classes.
- It is useful for object graphs where copying an existing instance is easier than building a new one.
- Make sure cloned objects do not share mutable state unless intentionally designed.

## How to use

- Define a common prototype interface with a clone method.
- Implement cloning in concrete prototype classes.
- Use the prototype object to create new instances when needed.

## Example file

The `prototype.cpp` file demonstrates the clone-based creation flow for the Prototype pattern.
