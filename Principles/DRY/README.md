# DRY Principle

## What is the DRY principle?

DRY means "Don't Repeat Yourself."

It tells us not to copy the same logic again and again in multiple places. If the same logic is repeated, it becomes harder to maintain and easier to introduce bugs.

## Problem it solves

When the same logic is written multiple times, updating it later becomes painful because every copy must be changed manually. It also increases the chance of inconsistent behavior.

Example:

- same validation logic written in many functions
- same calculation repeated in multiple classes
- same message formatting repeated in several modules

## Key idea

Extract repeated logic into a common function, class, or utility so it is defined once and reused everywhere.

## Important notes

- DRY is about reducing repetition of logic, not necessarily reducing all repetition in code.
- It improves maintainability and consistency.
- It reduces the risk of bugs from copied logic.
- It works best when logic is truly the same and should follow one rule.
- Repetition in code may still be acceptable if it improves clarity in some simple cases.

## When to use

Use DRY when:

- the same logic appears in different places
- a business rule is repeated in many methods
- the logic needs to be updated in the future

## Advantages

- easier maintenance
- less repeated code
- fewer bugs from inconsistent updates
- cleaner and more reusable design

## Disadvantages

- over-abstracting can make code harder to understand
- too much reuse can create unnecessary complexity
- sometimes small duplicates are clearer than a big abstraction

## Real-world example

Instead of writing the same formula or validation logic in several functions, create one helper function and call it from all required places.

## In this folder

The example `dry.cpp` demonstrates how logic can be extracted and reused instead of duplicated.

## How to run

```powershell
cd "System Design\Principles\DRY"
g++ -std=c++17 -Wall -Wextra dry.cpp -o dry.exe
./dry.exe
```

## Simple summary

The DRY principle encourages reusing logic instead of copying it. It keeps the system smaller, cleaner, and easier to maintain.
