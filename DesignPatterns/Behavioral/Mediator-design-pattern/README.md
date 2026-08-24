# Mediator Design Pattern

The Mediator pattern is a behavioral design pattern that centralizes communication between multiple objects through a mediator object instead of allowing objects to communicate directly with each other.

In simple words:

> Mediator means: let a central object coordinate communication between other objects.

## Problem It Solves

Without a mediator, multiple objects may communicate directly with each other.

Example:

```text
Alok → Akash
Alok → Rahul
Akash → Alok
Akash → Rahul
Rahul → Alok
Rahul → Akash
````

As the number of objects increases, communication becomes complicated and tightly coupled.

## Main Idea

Move communication logic into a separate mediator object.

Instead of:

```text
User A → User B
User A → User C
User B → User C
```

Use:

```text
          Mediator
         /   |   \
        ↓    ↓    ↓
      User User User
```

The users communicate through the mediator instead of directly communicating with each other.

## Structure

| Component          | Responsibility                                |
| ------------------ | --------------------------------------------- |
| Mediator Interface | Defines communication methods                 |
| Concrete Mediator  | Implements and coordinates communication      |
| Colleague          | Communicates through the mediator             |
| Concrete Colleague | Actual objects participating in communication |
| Client             | Creates and connects the objects              |

## Typical Flow

```text
Client creates mediator
        ↓
Client creates colleagues
        ↓
Colleagues are registered with mediator
        ↓
Colleague sends a request
        ↓
Mediator receives the request
        ↓
Mediator decides which colleagues should receive it
        ↓
Mediator communicates with required colleagues
```

## Chat Room Example

A chat application is a simple example.

```text
              ChatRoom
              Mediator
            /    |    \
           ↓     ↓     ↓
         Alok  Akash  Rahul
```

When Alok sends a message:

```text
Alok
 ↓
send()
 ↓
ChatRoom
 ↓
sendMessage()
 ↓
Akash.receive()
Rahul.receive()
```

Alok does not directly communicate with Akash or Rahul.

## Files In This Folder

Read in this order:

1. [mediator.cpp](mediator.cpp) - basic chat room mediator example

2. [chat.cpp](chat.cpp) - mediator with multiple users

3. [airport.cpp](airport.cpp) - airport control tower mediator example

4. [smart-home.cpp](smart-home.cpp) - mediator for smart home devices

## When To Use

Use Mediator when:

* many objects need to communicate with each other
* communication between objects is becoming complicated
* objects have too many direct dependencies
* you want to reduce coupling between objects
* communication logic should be centralized
* objects should not directly know about each other

## Advantages

* reduces coupling between objects
* centralizes communication logic
* makes communication easier to maintain
* makes it easier to add new colleagues
* separates communication logic from individual objects
* simplifies complex object interactions

## Disadvantages

* mediator can become too large
* can become a "God Object"
* communication logic can become complex
* adds extra classes and abstraction
* can be unnecessary for simple communication

## Real-World Examples

* chat applications
* airport control towers
* GUI dialog boxes
* smart home systems
* multiplayer games
* air traffic control
* workflow systems

## Easy Notes For Revision

**Simple idea:** centralize communication between multiple objects through a mediator.

**Example:** a `ChatRoom` coordinates communication between multiple `User` objects without users directly communicating with each other.

**Where to use:**

* when many objects communicate with each other
* when communication becomes complex
* when objects have many dependencies
* when direct communication creates tight coupling

**Advantages:**

* reduces coupling
* centralizes communication logic
* makes code easier to maintain
* simplifies complex interactions

**Disadvantages:**

* mediator can become too large
* adds extra abstraction
* can be unnecessary for simple communication

**Interview explanation:** Mediator centralizes communication between multiple objects. Instead of objects communicating directly with each other, they communicate through a mediator, which reduces coupling.

## Mediator vs Other Patterns

| Pattern  | Purpose                                           |
| -------- | ------------------------------------------------- |
| Mediator | Centralize communication between objects          |
| Iterator | Access elements one by one                        |
| Observer | Notify subscribers about changes                  |
| Command  | Encapsulate an action as an object                |
| Strategy | Change an algorithm or behavior                   |
| Facade   | Provide a simple interface to a complex subsystem |

## Mediator vs Observer

| Mediator                                 | Observer                              |
| ---------------------------------------- | ------------------------------------- |
| Coordinates communication                | Notifies observers                    |
| Usually handles many-to-many interaction | Usually one-to-many notification      |
| Central communication hub                | Subject notifies interested observers |
| Example: ChatRoom                        | Example: WeatherStation               |

Easy way to remember:

```text
Observer:
"Something changed, notify interested objects."

Mediator:
"Objects need to communicate, I'll coordinate them."
```

## OOP Concepts Used

### Abstraction

```cpp
virtual void sendMessage(...) = 0;
```

Defines a common communication contract.

### Inheritance

```cpp
class ChatRoom : public Mediator
```

ChatRoom implements the Mediator interface.

### Polymorphism

```cpp
Mediator* mediator;
```

User works with the Mediator abstraction instead of a specific implementation.

### Encapsulation

```cpp
private:
    vector<User*> users;
```

ChatRoom controls its internal user collection.

### Forward Declaration

```cpp
class User;
```

Allows `Mediator` to refer to `User*` before the complete `User` class is defined.

## SOLID Principles

### Single Responsibility Principle

Responsibilities are separated:

```text
User
→ Sends and receives messages

ChatRoom
→ Coordinates communication

Mediator
→ Defines communication contract
```

### Dependency Inversion Principle

User depends on:

```cpp
Mediator*
```

instead of:

```cpp
ChatRoom*
```

So User depends on an abstraction.

### Open/Closed Principle

Different Mediator implementations can be created without changing the basic Mediator interface.

## When NOT To Use

Don't use Mediator when communication is very simple.

For example:

```text
A → B
```

If there are only a few simple interactions, adding a mediator can introduce unnecessary complexity.

## Interview Recognition

When you hear:

> "Many objects need to communicate with each other."

Think:

```text
Many-to-many communication
          ↓
Centralize communication
          ↓
       Mediator
```

Ask yourself:

> "Can I move the communication logic into one central object?"

If yes, Mediator may be a good choice.

## Interview Explanation

### Short Answer

> The Mediator Design Pattern is a behavioral design pattern that centralizes communication between multiple objects. Instead of objects communicating directly with each other, they communicate through a mediator, which reduces coupling.

### Example

> A chat room is a common example. Users don't directly communicate with every other user. They send messages to the ChatRoom, and the ChatRoom decides which users should receive the message.

### Why Use It?

> I would use Mediator when communication between multiple objects becomes complex and creates many dependencies. It centralizes the communication logic and reduces coupling.

## Code Template

```cpp
class Colleague;

class Mediator
{
public:
    virtual void communicate(
        string message,
        Colleague* sender
    ) = 0;

    virtual ~Mediator() {}
};

class Colleague
{
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator)
        : mediator(mediator)
    {
    }

    void send(string message)
    {
        mediator->communicate(message, this);
    }
};

class ConcreteMediator : public Mediator
{
private:
    vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague)
    {
        colleagues.push_back(colleague);
    }

    void communicate(
        string message,
        Colleague* sender
    ) override
    {
        for (Colleague* colleague : colleagues)
        {
            if (colleague != sender)
            {
                // communicate
            }
        }
    }
};
```

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

Solution:
Introduce a central Mediator.

Main Components:
1. Mediator
2. Concrete Mediator
3. Colleague
4. Concrete Colleague
5. Client

Core Flow:
Colleague → Mediator → Other Colleagues

Example:
User → ChatRoom → User

Key Benefit:
Loose coupling.

Main Disadvantage:
Mediator can become a God Object.

Recognition Signal:
Many objects need to communicate with each other.

Memory:
Mediator = Central Communication Hub
```

## Golden Rule

```text
Many-to-many communication
          ↓
Centralize communication
          ↓
       Mediator
```

> **Mediator = "I'll coordinate everyone."**

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Behavioral\Mediator-design-pattern"

g++ -std=c++17 -Wall -Wextra mediator.cpp -o mediator.exe

./mediator.exe
```

```
```
