# Mediator Design Pattern

The Mediator pattern centralizes communication between multiple objects. Instead of objects talking directly to each other, they send requests through one mediator object.

In simple words:

> Mediator means: one central object coordinates communication.

## Problem It Solves

Without a mediator, many objects may directly depend on each other.

```text
User A -> User B
User A -> User C
User B -> User A
User B -> User C
User C -> User A
User C -> User B
```

As the number of objects grows, communication becomes hard to manage and tightly coupled.

## Main Idea

Move communication logic into a separate mediator class.

```text
User A
User B  ->  Mediator  ->  required users
User C
```

Each user knows the mediator, but users do not need to know each other directly.

## Structure

| Component | Responsibility |
|---|---|
| Mediator interface | Defines communication methods |
| Concrete mediator | Coordinates communication |
| Colleague | Object that communicates through the mediator |
| Client | Creates and connects mediator and colleagues |

## Typical Flow

```text
Client creates mediator
Client creates colleagues
Client registers colleagues with mediator
Colleague sends message
Mediator receives message
Mediator forwards message to required colleagues
```

## Files In This Folder

1. [mediator.cpp](mediator.cpp) - basic chat room mediator example
2. [airport.cpp](airport.cpp) - airport control tower mediator example

## When To Use

- many objects need to communicate with each other
- communication logic is becoming complicated
- objects have too many direct dependencies
- communication rules should be centralized
- objects should not directly know about each other

## When Not To Use

- communication is simple
- only one or two objects interact
- adding a mediator would make the code harder to understand

## Advantages

- reduces direct coupling
- centralizes communication rules
- keeps colleague classes simpler
- makes object interaction easier to change

## Disadvantages

- mediator can become too large
- adds an extra abstraction
- communication logic can become hidden inside one class

## Real-World Examples

- chat room
- airport control tower
- GUI dialog controller
- smart home controller
- workflow coordinator

## OOP Concepts Used

- abstraction: colleagues depend on a mediator interface
- composition: colleagues store a mediator reference
- encapsulation: communication rules stay inside the mediator
- polymorphism: different mediator implementations can be used

## Interview Explanation

Mediator is used when many objects communicate with each other and direct communication creates tight coupling. A mediator object coordinates the communication, so individual objects stay simpler and do not need to know each other directly.

## Quick Revision

```text
Pattern:
Mediator

Type:
Behavioral Design Pattern

Intent:
Centralize communication between multiple objects.

Problem:
Many-to-many communication creates tight coupling.

Main Components:
1. Mediator
2. Concrete mediator
3. Colleague
4. Client

Core Flow:
Colleague -> Mediator -> Other colleagues

Example:
User -> ChatRoom -> User

Memory:
Mediator = central communication coordinator
```

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Behavioral\Mediator-design-pattern"
g++ -std=c++17 -Wall -Wextra mediator.cpp -o mediator.exe
./mediator.exe
```
