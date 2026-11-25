# Command

Command represents a request as an object. The invoker can trigger an action without knowing which receiver performs it. This is useful for interchangeable actions and can support queues, logging, or undo when those features are implemented.

## Roles

| Role | Responsibility |
|---|---|
| Command | Common operation, usually `execute()` |
| Concrete command | Connects a request to a receiver operation |
| Receiver | Performs the actual work |
| Invoker | Triggers the command |
| Client | Creates objects and wires the command to its receiver |

## Examples

| File | Example |
|---|---|
| [`command.cpp`](command.cpp) | Basic command and remote control |
| [`music_player.cpp`](music_player.cpp) | Music player actions |
| [`home_control.cpp`](home_control.cpp) | Smart home actions |

Start with `command.cpp`: find where `main()` creates the receiver and command, passes it to the invoker, and triggers `execute()`. The invoker should only need the command interface.

## Trade-off

Commands add classes and wiring. Use them when requests need to be selected, stored, queued, or otherwise handled independently. A direct method call is simpler for a fixed action with no such need.

## Build

Run from this directory, one source file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra command.cpp -o command.exe
.\command.exe
```

Substitute `music_player.cpp` or `home_control.cpp` to run the other examples.
