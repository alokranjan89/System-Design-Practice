# KISS Principle

## What is the KISS principle?

KISS stands for "Keep It Simple, Stupid."

It means that we should prefer the simplest solution that solves the problem correctly, instead of adding unnecessary complexity.

## Problem it solves

When developers add too many features, abstractions, or unnecessary patterns, the system becomes harder to read, debug, and maintain. The code may work, but it becomes fragile and expensive to change.

## Key idea

Solve the current problem directly and clearly. Avoid adding advanced design, extra layers, or complicated logic unless they are truly needed.

## Important notes

- Simpler code is usually easier to read.
- Simpler code is easier to test and debug.
- A good design is not necessarily the most complicated design.
- Overengineering often causes more maintenance cost than value.
- Simplicity should help the solution, not reduce its correctness.

## When to use

Use KISS when:

- the requirement is straightforward
- the cost of complexity is higher than the value
- you want maintainable code without unnecessary abstraction

## Advantages

- easier to read and understand
- easier to test and debug
- faster onboarding for new developers
- lower maintenance cost
- fewer hidden issues

## Disadvantages

- too much simplicity may require refactoring later if the system grows
- requires judgment to decide what is truly simple and what is incomplete

## Real-world example

A simple function that validates user input is better than a large framework or overengineered validation system if the requirement is small and direct.

## In this folder

`kiss.cpp` demonstrates a simple implementation approach without unnecessary complexity.

## How to run

```powershell
cd "System Design\Principles\KISS"
g++ -std=c++17 -Wall -Wextra kiss.cpp -o kiss.exe
./kiss.exe
```

## Simple summary

KISS reminds us that the best solution is usually the simplest one that works. Simplicity improves readability, maintainability, and long-term quality.
