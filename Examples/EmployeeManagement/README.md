# Employee Management

This example uses an abstract `Employee` base class and concrete `Developer` and `Manager` subclasses.

## Key Concepts

- Abstract classes and pure virtual methods
- Polymorphism via `Employee*`
- `Company` stores employees and executes their work flow
- Manual cleanup through the `Company` destructor

## Main Classes

| Class | Responsibility |
|---|---|
| `Employee` | Base class with login, logout, and abstract `work()` behavior |
| `Developer` | Implements work by writing code |
| `Manager` | Implements work by assigning tasks |
| `Company` | Stores employees and calls their common work flow |

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\EmployeeManagement"
g++ -std=c++17 -Wall -Wextra employee_management.cpp -o employee_management.exe
./employee_management.exe
```
