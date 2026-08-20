# Command Design Pattern

## What is the Command pattern?

The Command pattern is a behavioral design pattern that converts a request into an object.

Instead of calling an action directly, we wrap that action inside a command class. The object that triggers the action does not need to know how the action is performed.

In simple words:

> Command pattern means: make an action a separate object.

## Why is it behavioral?

Behavioral design patterns focus on how objects communicate and divide responsibilities.

The Command pattern is behavioral because it controls communication between the object that asks for an action and the object that actually performs that action.

## Problem it solves

Without the Command pattern, the invoker directly calls methods on the receiver.

Pseudo-code example:

```cpp
void pressButton()
{
    light.turnOn();
}
```

This creates tight coupling:

- `RemoteControl` must know about `Light`
- adding a new action means changing `RemoteControl`
- undo, redo, queue, log, or schedule operations become harder
- the request and execution logic are mixed together

## Main idea

Separate the request into its own object.

The invoker only knows that it has a command and can call `execute()`.

It does not know:

- which receiver is used
- what action will happen
- how the action is implemented

## Structure

The Command pattern usually has these parts:

| Component | Responsibility | In this code |
|---|---|---|
| Receiver | Performs the actual work | `Light` |
| Command Interface | Declares the common operation | `Command` |
| Concrete Command | Implements a specific request | `TurnOnCommand`, `TurnOffCommand` |
| Invoker | Triggers the command | `RemoteControl` |
| Client | Creates and connects objects | `main()` |

## Files In This Folder

Read in this order:

1. [command.cpp](command.cpp) - basic remote control and light example
2. [musicPlayer.cpp](musicPlayer.cpp) - extra practice with play, pause, and stop commands

## Flow of execution

```text
Client creates Receiver
Client creates Concrete Command with Receiver
Client gives Command to Invoker
Invoker calls execute()
Concrete Command calls Receiver method
Receiver performs real work
```

For this folder:

```text
main()
  creates Light
  creates TurnOnCommand(light)
  gives it to RemoteControl
  remote.pressButton()
  command->execute()
  light.turnOn()
```

## Code mapping

### 1. Receiver

The receiver knows how to do the actual work.

```cpp
class Light
{
public:
    void turnOn()
    {
        cout << "Light is ON" << endl;
    }

    void turnOff()
    {
        cout << "Light is OFF" << endl;
    }
};
```

Here, `Light` is the real object that performs the action.

### 2. Command interface

The command interface defines what every command must support.

```cpp
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};
```

Every command must implement `execute()`.

The invoker can work with any command through this interface.

### 3. Concrete commands

Concrete commands connect the request with the receiver.

```cpp
class TurnOnCommand : public Command
{
private:
    Light& light;

public:
    TurnOnCommand(Light& light)
        : light(light)
    {
    }

    void execute() override
    {
        light.turnOn();
    }
};
```

`TurnOnCommand` stores a reference to `Light` and calls `light.turnOn()` when executed.

Similarly:

```cpp
class TurnOffCommand : public Command
{
private:
    Light& light;

public:
    TurnOffCommand(Light& light)
        : light(light)
    {
    }

    void execute() override
    {
        light.turnOff();
    }
};
```

`TurnOffCommand` calls `light.turnOff()`.

### 4. Invoker

The invoker triggers the command.

```cpp
class RemoteControl
{
private:
    Command* command;

public:
    RemoteControl(Command* command)
        : command(command)
    {
    }

    void setCommand(Command* command)
    {
        this->command = command;
    }

    void pressButton()
    {
        command->execute();
    }
};
```

`RemoteControl` does not know about `Light`, `turnOn()`, or `turnOff()`.

It only knows:

```cpp
command->execute();
```

That is the main benefit of the pattern.

### 5. Client

The client creates all objects and connects them.

```cpp
int main()
{
    Light light;

    TurnOnCommand turnOn(light);
    TurnOffCommand turnOff(light);

    RemoteControl remote(&turnOn);
    remote.pressButton();

    remote.setCommand(&turnOff);
    remote.pressButton();

    return 0;
}
```

The client decides which command should be used.

## Output

```text
Light is ON
Light is OFF
```

## Important points to remember

- Command pattern encapsulates a request as an object.
- The invoker is separated from the receiver.
- The invoker only calls `execute()`.
- Concrete commands decide which receiver method to call.
- The receiver contains the actual business logic.
- Commands can be changed at runtime.
- It supports undo, redo, logging, queueing, and scheduling.
- It follows the Open/Closed Principle because new commands can be added without changing the invoker.

## When to use

Use the Command pattern when:

- you want to decouple the object that sends a request from the object that handles it
- you need buttons, menu items, or shortcuts that trigger different actions
- you want to support undo and redo
- you want to queue or schedule operations
- you want to log operations
- you want to store requests and execute them later

## Real-world examples

- remote control buttons
- text editor undo and redo
- menu items in GUI applications
- job queues
- task schedulers
- transaction systems
- macro recording tools

## Advantages

- reduces coupling between invoker and receiver
- makes new commands easy to add
- makes runtime command switching simple
- supports undo and redo design
- helps build queues, logs, and scheduled tasks
- keeps each action in a separate class

## Disadvantages

- increases the number of classes
- can feel heavy for very small actions
- client must create and connect command objects correctly
- simple direct method calls may be enough for tiny programs

## Command vs Strategy

| Command | Strategy |
|---|---|
| Encapsulates a request or action | Encapsulates an algorithm |
| Usually has `execute()` | Usually has a behavior-specific method |
| Often used for buttons, queues, undo/redo | Often used for choosing between algorithms |
| Invoker triggers the command | Context uses the selected strategy |

Simple difference:

- Strategy changes how something is done.
- Command represents what should be done.

## Command vs Observer

| Command | Observer |
|---|---|
| One invoker triggers a command | One subject notifies many observers |
| Request is stored as an object | Event notification is broadcast |
| Good for undo, queue, scheduling | Good for event-driven updates |

## Interview explanation

The Command pattern wraps a request inside an object. The invoker calls a common `execute()` method without knowing the actual receiver or operation. This reduces coupling and allows features like undo, redo, command queues, logging, and runtime action switching.

## Quick revision

```text
Intent:
Encapsulate a request as an object.

Main classes:
Receiver -> does the real work
Command -> common interface
ConcreteCommand -> calls receiver method
Invoker -> calls execute()
Client -> wires objects together

In this example:
Light -> Receiver
Command -> Interface
TurnOnCommand / TurnOffCommand -> Concrete Commands
RemoteControl -> Invoker
main() -> Client
```

## How to run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Behavioral\command-design-pattern"
g++ -std=c++17 -Wall -Wextra command.cpp -o command.exe
./command.exe
```

To run the music player example:

```powershell
g++ -std=c++17 -Wall -Wextra musicPlayer.cpp -o musicPlayer.exe
./musicPlayer.exe
```

## Simple summary

The Command pattern is used when you want to turn actions into objects. It keeps the object that triggers an action separate from the object that performs the action, making the code flexible, extendable, and useful for undo, redo, queues, logs, and scheduled tasks.
