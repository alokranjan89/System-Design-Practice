# Observer Design Pattern

## What does design mean?

Design is the planning of how software components should be structured, communicate, and divide responsibilities. It helps us build systems that are easier to understand, easier to change, and less likely to break when requirements evolve.

We use design in real software whenever we need to:

- manage updates between objects
- keep components loosely coupled
- avoid repeating logic in multiple places
- make the code easier to extend later
- create systems that react to changes automatically

Good design is not just writing code; it is deciding the correct structure before building the solution.

## What is a behavioral design pattern?

A behavioral design pattern focuses on how objects interact and communicate with each other. It helps define responsibilities and control the flow of messages between objects.

The Observer pattern is a behavioral design pattern because it defines a relationship where one object notifies many dependent objects when its state changes.

## What is the Observer pattern?

The Observer pattern is used when one object needs to notify other objects automatically when something important changes.

In simple words:

- there is one subject (publisher)
- there are many observers (subscribers)
- observers are interested in the subject's state
- when the subject changes, it notifies all observers

This is very useful when we want a system to react immediately to changes without tightly coupling everything together.

## Problem it solves

Without this pattern, one object may need to know too much about many other objects. This creates tight coupling and makes the code harder to maintain.

Example:

- A YouTube channel should notify all subscribers when a new video is uploaded.
- A stock price system should notify all clients when the price changes.
- A weather station should update all display panels when temperature changes.

If we manually call each object in every place, the code becomes messy and hard to extend.

## Key idea

The subject maintains a list of observers and provides methods for:

- adding an observer
- removing an observer
- notifying all observers

Each observer implements a common interface so the subject does not need to know the exact class of each observer.

## Important notes

- The subject is the source of change.
- Observers are dependent on the subject.
- Observers subscribe to receive updates.
- The subject notifies all registered observers when the state changes.
- The pattern reduces direct dependency between objects.
- It helps maintain one-to-many relationships cleanly.
- It supports event-driven behavior.
- It is useful when many components need to react to the same event.
- It follows the principle of loose coupling.
- The subject should not directly depend on concrete observer classes; it should depend on an interface or abstract contract.

## When to use

Use the Observer pattern when:

- one object changes and many others need to know
- a change in one module should trigger updates in other modules
- you want a one-to-many relationship between objects
- you want to avoid frequent polling or manual update calls
- you need event-driven communication

## Advantages

- loose coupling between subject and observers
- easy to add or remove observers
- supports dynamic behavior at runtime
- reduces hardcoded dependencies
- good for event-driven systems

## Disadvantages

- can become complex if too many observers are involved
- debugging can be harder because many objects react to one event
- memory leaks may happen if observers are not unsubscribed properly
- order of notifications may not always be predictable

## Real-world examples

- email subscribers receiving updates from a newsletter
- stock market apps notifying users about price changes
- weather stations sending updates to multiple displays
- social media followers receiving notifications
- YouTube subscribers receiving new video alerts

## Easy Notes For Revision

**Simple idea:** when one object changes, all subscribed objects are notified automatically.

**Example:** when a YouTube channel uploads a video, all subscribers receive a notification.

**Where to use:**
- event notification systems
- publish-subscribe flows
- UI updates after data changes
- stock price updates
- notification systems

**Advantages:**
- keeps subject and observers loosely coupled
- observers can be added or removed at runtime
- supports one-to-many communication
- good for event-driven systems

**Disadvantages:**
- notification flow can be harder to debug
- too many observers can make behavior hard to track
- observers should be removed properly to avoid stale references
- notification order may matter but is not always obvious

**Interview explanation:** Observer creates a one-to-many relationship. The subject stores observers and notifies them whenever its state changes, without depending on their concrete classes.

## In this folder

- `youtube_notification.cpp` demonstrates the Observer pattern with a YouTube channel and its subscribers.

## How to run

```powershell
cd "System Design\DesignPatterns\Behavioral\ObserverDesignPattern"
g++ -std=c++17 -Wall -Wextra youtube_notification.cpp -o youtube_notification.exe
./youtube_notification.exe
```

## Simple summary

The Observer pattern is used when one object should inform many others about a change without tightly coupling them together. It is a clean and scalable way to handle event-based communication.
