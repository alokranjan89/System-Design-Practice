# SOLID

SOLID is a group of five object-oriented design principles. They help reason about responsibilities and dependencies, but applying them mechanically can add needless interfaces and classes.

| Principle | Short meaning | Example |
|---|---|---|
| Single Responsibility (SRP) | Keep a module focused around one reason to change | [`single_responsibility.cpp`](single_responsibility.cpp) |
| Open/Closed (OCP) | Make expected variation possible without repeatedly editing stable logic | [`open_closed.cpp`](open_closed.cpp) |
| Liskov Substitution (LSP) | A subtype should preserve the expectations of its base type | [`liskov_substitution.cpp`](liskov_substitution.cpp) |
| Interface Segregation (ISP) | Keep clients from depending on operations they do not use | [`interface_segregation.cpp`](interface_segregation.cpp) |
| Dependency Inversion (DIP) | Keep high-level policy from depending directly on low-level details | [`dependency_inversion.cpp`](dependency_inversion.cpp) |

Read one example at a time. Ask what change the design handles and whether its extra structure is justified; a small program may be clearer without a pattern or abstraction.

Compile from the repository root, for example:

```powershell
g++ -std=c++17 -Wall -Wextra Principles/Solid/single_responsibility.cpp -o srp.exe
.\srp.exe
```
