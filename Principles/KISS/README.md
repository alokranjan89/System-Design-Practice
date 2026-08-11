# KISS Principle

KISS means "Keep It Simple, Stupid."

## Meaning

Design and implement the simplest solution that satisfies the current requirement.

## What this example shows

- Simple code is easier to read.
- Simple code is easier to debug.
- Extra features should not be added unless they are needed.

## Advantages

- Easier maintenance.
- Easier testing.
- Fewer unnecessary moving parts.
- Faster understanding for new developers.

## Disadvantages

- A very simple design may need changes when requirements grow.
- It requires judgment to know what is simple versus incomplete.

## How to run

```powershell
cd "System Design\Principles\KISS"
g++ -std=c++17 -Wall -Wextra kiss.cpp -o kiss.exe
./kiss.exe
```
