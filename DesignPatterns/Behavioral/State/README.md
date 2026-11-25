# State

State moves state-dependent behavior into state objects. A context delegates actions to its current state, which may transition the context to another state.

## Example

[`vending.cpp`](vending.cpp) models a vending machine with `NoMoneyState`, `HasMoneyState`, and `ProductSelectedState`. Follow the calls to `insertMoney()`, `selectProduct()`, and `dispense()` to see which transitions are allowed.

## When it helps

Use State when a growing set of conditionals repeats state checks and each state has distinct rules. For only a few simple states, a conditional may be easier to read. State objects add indirection, so make transitions explicit.

## Build

From this directory:

```powershell
g++ -std=c++17 -Wall -Wextra vending.cpp -o vending.exe
.\vending.exe
```
