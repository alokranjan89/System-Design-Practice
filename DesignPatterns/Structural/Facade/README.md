# Facade

Facade provides a simple interface to a larger subsystem. It coordinates multiple subsystem objects so the client does not need to know their methods or initialization sequence.

## Roles

| Role | Class | Responsibility |
|---|---|---|
| Facade | `HomeTheaterFacade` | Exposes `watchMovie()` and coordinates the subsystem |
| Subsystems | `TV`, `SoundSystem`, `DVDPlayer` | Perform their own operations |
| Client | `main()` | Calls the Facade instead of the subsystem classes |

`watchMovie()` turns on the TV and sound system, then starts the DVD player. The subsystem classes remain independent and can still be used directly.

## Typical code

```cpp
class TV {
public:
    void turnOn();
};

class SoundSystem {
public:
    void turnOn();
};

class DVDPlayer {
public:
    void play();
};

class HomeTheaterFacade {
private:
    TV tv;
    SoundSystem sound;
    DVDPlayer dvd;

public:
    void watchMovie() {
        tv.turnOn();
        sound.turnOn();
        dvd.play();
    }
};

int main() {
    HomeTheaterFacade homeTheater;
    homeTheater.watchMovie();
    return 0;
}
```

The client calls only `watchMovie()`. The Facade owns the correct subsystem sequence and calls each subsystem directly.

## Where to use

- Use a Facade when a client needs only a high-level operation, such as `startComputer()` or `placeOrder()`, while several subsystem calls happen underneath.
- Use it when subsystem methods must be called in a specific order.
- Use it for libraries or legacy modules where clients should not depend directly on many internal classes.
- Do not use it only to add more wrapping; provide direct subsystem access when fine-grained control is required.

## Advantages

- Gives clients a simple, intent-focused API.
- Keeps subsystem details and call order in one place.
- Reduces coupling and makes the subsystem easier to change without affecting every client.

## Disadvantages

- The Facade can become large if too many subsystem operations are added.
- Clients needing fine-grained control may bypass or supplement the Facade.
- It can hide subsystem behavior rather than replace the need to understand it.

Facade simplifies access to an existing subsystem. Adapter changes one interface into another interface; Decorator keeps an interface while adding behavior.

## Build and run

Run from this directory:

```powershell
g++ -std=c++17 -Wall -Wextra Facade.cpp -o Facade.exe
.\Facade.exe
```
