# State Design Pattern

The State pattern is a behavioral design pattern that lets an object change its behavior when its internal state changes.

In simple words:

> State means: the same action behaves differently depending on the current state of the object.

## Problem It Solves

Without State, one class often contains many `if` or `switch` checks:

```cpp
if (state == "NO_MONEY") { ... }
else if (state == "HAS_MONEY") { ... }
else if (state == "PRODUCT_SELECTED") { ... }
```

As states and actions increase, the class becomes hard to maintain.

## Main Idea

Move behavior for each state into a separate class.

```text
VendingMachine
    delegates action to current State
NoMoneyState / HasMoneyState / ProductSelectedState
    handle behavior and decide next state
```

## Files In This Folder

1. [vending.cpp](vending.cpp) - vending machine state transition example

## Vending Machine Flow

```text
NoMoneyState
    insertMoney()
HasMoneyState
    selectProduct()
ProductSelectedState
    dispense()
NoMoneyState
```

## When To Use

- object behavior depends on current state
- many conditionals check the same state variable
- state transitions should be explicit
- each state has different rules for the same actions

## When Not To Use

- only one or two simple states exist
- state-specific behavior is very small
- adding state classes would make the code harder to read

## Interview Explanation

State separates state-specific behavior into separate classes. The context object keeps a reference to the current state and delegates actions to it. Each state class handles behavior for that state and can move the context to the next state.

## Quick Revision

```text
Pattern:
State

Type:
Behavioral Design Pattern

Intent:
Change object behavior when internal state changes.

Main Components:
1. State interface
2. Concrete states
3. Context object

Example:
VendingMachine delegates to NoMoneyState, HasMoneyState, or ProductSelectedState.

Memory:
State = behavior depends on current condition
```

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Behavioral\state-design-pattern"
g++ -std=c++17 -Wall -Wextra vending.cpp -o vending.exe
./vending.exe
```
