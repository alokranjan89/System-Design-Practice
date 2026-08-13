# Strategy Design Pattern

## What does design mean?

Design is the process of planning how a system should be structured so that it is easy to understand, maintain, and extend. In software, design decides how classes, modules, and responsibilities are arranged.

We use design in real systems whenever we need to:

- separate business logic from implementation details
- create reusable solutions
- handle future changes without rewriting the whole system
- reduce code repetition and complexity
- make code easier to test and maintain

Design helps us create software that is not only functional, but also clean and scalable.

## What is a behavioral design pattern?

A behavioral design pattern deals with how objects interact and share responsibilities. It focuses on communication, workflows, and delegation of behavior.

The Strategy pattern is a behavioral pattern because it changes how an object behaves by selecting a different strategy at runtime.

## What is the Strategy pattern?

The Strategy pattern allows an object to change its behavior by using different interchangeable algorithms or strategies.

Instead of writing long `if-else` blocks for different behaviors, we create separate classes with a common interface. The object then chooses a strategy based on the situation.

## Problem it solves

When an object has multiple ways of doing the same task, writing all the logic inside one class makes it difficult to manage and extend.

Example:

- payment options: credit card, UPI, PayPal
- notification methods: email, SMS, push notification
- sorting algorithms: quick sort, merge sort, insertion sort

If all logic is placed in a single class, it becomes large and hard to maintain.

## Key idea

Create a common interface, build different implementations for each behavior, and inject the chosen strategy into the context object.

This way:

- the main object stays simple
- each behavior has its own class
- switching behavior is easy
- new strategies can be added without changing old logic

## Important notes

- The strategy encapsulates the behavior.
- The context is the object using the strategy.
- Both follow a common interface.
- The behavior can be changed at runtime.
- It avoids large conditional logic.
- It supports the Open/Closed Principle.
- It keeps the code cleaner and more flexible.
- It is ideal when multiple algorithms solve the same problem.
- It is especially useful when the selected behavior might change based on user input or conditions.

## When to use

Use the Strategy pattern when:

- multiple algorithms or behaviors can be used for the same task
- behavior should be selected dynamically at runtime
- you want to avoid long `if-else` chains
- different behaviors share the same goal but use different implementations

## Advantages

- easy to add new strategies
- clean separation of responsibilities
- better maintainability
- runtime behavior switching is simple
- reduces duplication and conditional complexity

## Disadvantages

- adds extra classes
- client code must choose the right strategy
- can be over-engineering for very small systems

## Real-world examples

- different payment methods in an e-commerce app
- choosing notification type based on user preference
- selecting sorting strategy for different data sizes
- applying different compression algorithms based on file type

## In this folder

- `payment.cpp` uses different payment strategies behind a shared interface.
- `notification.cpp` uses different notification strategies behind a common abstraction.

## How to run

```powershell
cd "System Design\DesignPatterns\Behavioral\StrategyDesignPattern"
g++ -std=c++17 -Wall -Wextra payment.cpp -o payment.exe
./payment.exe
```

Replace `payment.cpp` with `notification.cpp` to run the notification example.

## Simple summary

The Strategy pattern is used when the same task can be performed in different ways, and the best approach should be selected at runtime. It helps keep the code flexible, clean, and easy to extend.
