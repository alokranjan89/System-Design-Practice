# Strategy Design Pattern

The Strategy pattern lets an object change its behavior by using different interchangeable strategy classes.

## What this folder shows

- `payment.cpp` demonstrates different payment methods behind one common interface.
- `notification.cpp` demonstrates different notification methods behind one common interface.
- The client code depends on an abstraction instead of concrete behavior classes.

## Key idea

Instead of writing many `if-else` conditions for behavior changes, create separate strategy classes and pass the required strategy to the context object.

## When to use

- When multiple algorithms or behaviors can be used for the same task.
- When behavior should be selected or changed at runtime.
- When you want to avoid large conditional blocks.

## Advantages

- Easy to add a new strategy without changing existing strategies.
- Keeps each behavior in its own class.
- Makes runtime behavior switching simple.

## Disadvantages

- Adds more classes.
- Client code must know which strategy to choose.
- Can be overkill when there are only one or two simple behaviors.

## How to run

```powershell
cd "System Design\DesignPatterns\Behavioral\StrategyDesignPattern"
g++ -std=c++17 -Wall -Wextra payment.cpp -o payment.exe
./payment.exe
```

Replace `payment.cpp` with `notification.cpp` to run the notification example.
