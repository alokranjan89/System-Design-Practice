# YAGNI Principle

## What does design mean?

Design is the practice of building software in a way that is structured, understandable, and easier to change. A strong design avoids unnecessary complexity and wasted effort.

We use design to:

- plan solutions before implementing them
- reduce unnecessary work
- keep systems focused on actual requirements
- improve future maintainability

## What is the YAGNI principle?

YAGNI means "You Aren't Gonna Need It."

It tells developers not to build features or code paths that are not required right now. In other words, do not over-engineer for possible future needs unless there is real evidence they are needed.

## Problem it solves

Without YAGNI, developers may add unused features, complicated abstractions, and extra modules that never get used. This adds cost and confusion without delivering value.

## Key idea

Implement only what is needed for the current requirement. If a future feature becomes necessary, it can be added later with better information at that time.

## Important notes

- YAGNI is about avoiding unnecessary complexity.
- It keeps the codebase smaller and easier to understand.
- It helps prevent wasted effort and time.
- It does not mean ignoring future maintainability.
- It means avoiding speculative design based only on guesswork.

## When to use

Use YAGNI when:

- requirements are clear and limited
- the code is still small or evolving
- you want to avoid building features nobody asked for
- you do not yet have evidence that a future requirement is necessary

## Advantages

- saves development time
- reduces unused code
- lower maintenance cost
- improves focus on current requirements
- makes the project easier to adapt later

## Disadvantages

- some future changes may require refactoring
- teams may feel limited if they avoid preparing for likely changes
- requires discipline to avoid guessing too much

## Real-world example

If a system only needs email notifications today, do not build support for SMS, push, and WhatsApp messaging unless they are required right now.

## In this folder

`yagni.cpp` demonstrates a simple implementation that follows the principle of not adding unnecessary features.

## How to run

```powershell
cd "System Design\Principles\YAGNI"
g++ -std=c++17 -Wall -Wextra yagni.cpp -o yagni.exe
./yagni.exe
```

## Simple summary

YAGNI tells us to avoid building features we do not need yet. It keeps the code focused, simpler, and easier to maintain while the actual requirements are still clear.
