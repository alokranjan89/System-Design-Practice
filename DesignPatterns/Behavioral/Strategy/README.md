# Strategy

Strategy puts interchangeable ways of doing a task behind one interface. A context uses the selected strategy and does not need to contain every algorithm itself.

## Examples

| File | Strategy family |
|---|---|
| [`payment.cpp`](payment.cpp) | Payment methods |
| [`notification.cpp`](notification.cpp) | Notification channels |

Identify the strategy interface, its concrete implementations, and the object that invokes the selected behavior. Trace how `main()` chooses or changes the strategy.

## When it helps

Use Strategy when behavior varies and callers need to select or replace it. The extra classes and object wiring are unnecessary for one fixed, simple behavior. The pattern can help extension, but it does not guarantee that adding a strategy requires no other changes.

## Build

From this directory, compile one example at a time:

```powershell
g++ -std=c++17 -Wall -Wextra payment.cpp -o payment.exe
.\payment.exe
```

Substitute `notification.cpp` for the other example.
