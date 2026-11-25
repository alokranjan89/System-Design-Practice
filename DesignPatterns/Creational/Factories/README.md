# Factory Patterns

Factories move object creation behind a function or abstraction so client code does not need to construct every concrete type directly.

## Examples

| Style | Source | Core idea |
|---|---|---|
| Simple Factory | [`simple_factory.cpp`](simple_factory.cpp) | One function selects and creates a product |
| Factory Method | [`factory_method.cpp`](factory_method.cpp) | Concrete creators choose which product to create |
| Abstract Factory | [`abstract_factory.cpp`](abstract_factory.cpp) | A factory creates a family of related products |

Start with Simple Factory, then compare the creator roles in Factory Method and Abstract Factory. The [quick reference](factory_method_quick_reference.md) summarizes the distinction.

## Choosing

| Need | Consider |
|---|---|
| A few choices and simple creation logic | Simple Factory |
| Different creator types own creation decisions | Factory Method |
| Related products must be created as a consistent family | Abstract Factory |

Trade-off: factories add indirection and often more types. Use one when creation logic or product variation justifies that structure.

## Build

Run from this directory, one source file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra simple_factory.cpp -o simple_factory.exe
.\simple_factory.exe
```

Substitute `factory_method.cpp` or `abstract_factory.cpp` to run the other examples.
