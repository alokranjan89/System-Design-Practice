# Composite Design Pattern

## What is it?
The Composite Design Pattern is used when you want to treat individual objects and groups of objects in the same way.

It helps build a tree-like structure where:
- a single object is a leaf
- a group of objects is a composite
- both follow the same interface

## Why use it?
It allows the client code to work with objects uniformly without caring whether the object is:
- a single employee
- a manager with many subordinates
- a nested hierarchy of employees

This makes the code simpler and more scalable.

## Real-world example
In this example:
- `Employee` is a leaf node
- `Manager` is a composite node
- both inherit from the same base class `EmployeeComponenet`

The common method `getSalary()` is used in both cases.

## Structure
- `EmployeeComponenet` -> common interface
- `Employee` -> leaf node with no children
- `Manager` -> container node that stores child objects

## How it works
A manager can hold other employees or even other managers.
When we call `getSalary()` on a manager, it:
1. adds its own salary
2. calls `getSalary()` on each child
3. sums all results

This creates a recursive structure.

## Advantages
- Treats single objects and groups uniformly.
- Makes tree-like structures easy to build and traverse.
- Reduces conditional logic in client code.
- Supports recursive operations naturally.
- Easy to extend with new types of components.

## Disadvantages
- Can be difficult to design if the hierarchy is not clearly defined.
- The base class can become too general and heavy.
- Managing child relationships may become complex in large trees.
- Sometimes it is overkill for simple object relationships.

## Where it is used
The Composite Pattern is useful in:
- company hierarchy (employees, managers, departments)
- file and folder systems
- UI component trees (buttons, panels, windows)
- menu and submenu structures
- product categories and subcategories
- graphics and document object models

## When to use it
Use this pattern when:
- objects form a tree-like structure
- you want to treat leaf and composite objects in the same way
- a recursive operation is needed on all children

## Example in this project
See the implementation in [employee.cpp](employee.cpp).

## Summary
The Composite Pattern helps represent part-whole hierarchies in a clean way. It allows a single object and a group of objects to be treated the same, which is exactly what we do here with employees and managers.
