# Object-Oriented Programming (OOP) Notes

OOP organizes a program around **objects**: values that combine state (data) with behavior (functions). In C++, a class defines a type of object, and each object is an instance of that class.

```cpp
class BankAccount {
public:
    void deposit(double amount) { balance += amount; }
    double getBalance() const { return balance; }

private:
    double balance = 0;
};

BankAccount account; // object
```

## Class and object

- **Class:** a blueprint that defines data and operations.
- **Object:** an instance of a class with its own state.
- **Member variable:** data belonging to an object (or class, if `static`).
- **Member function:** an operation provided by a class.
- **Constructor:** initializes an object. Prefer constructors that leave the object in a valid state.
- **Destructor:** runs when an object's lifetime ends; use it to release resources when needed. In C++, prefer RAII types such as `std::vector` and `std::unique_ptr` to manage resources automatically.

## The four pillars

Read each pillar separately:

1. [Encapsulation](encapsulation.cpp)
2. [Abstraction](abstraction.cpp)
3. [Inheritance](inheritance.cpp)
4. [Polymorphism](polymorphism.cpp)

Each file has a runnable example and a practice exercise in its comments. Compile one at a time with `g++ -std=c++17 -Wall -Wextra file.cpp -o practice.exe`.

## Object relationships

- **Is-a:** `Circle` is a `Shape`; may fit public inheritance.
- **Has-a / composition:** `Car` owns an `Engine`; the part's lifetime is tied to the whole.
- **Aggregation:** a `Team` refers to `Player` objects whose lifetimes are managed elsewhere.
- **Uses-a / dependency:** a function temporarily uses a service, often through a reference or parameter.

Choose relationships based on ownership and behavior, not just on how nouns sound.

## Access and `const`

- `public`: callers may use the member.
- `private`: only the class (and its friends) may use the member.
- `protected`: the class and derived classes may use the member; avoid exposing it to subclasses without a reason.
- Mark operations that do not change observable object state as `const`, such as `double area() const`.

## When OOP helps

OOP is useful when a domain has stateful entities with clear responsibilities, or when implementations need to be substituted behind stable interfaces. It is not a requirement for every program: a small calculation may be simpler as a function. Keep classes focused and avoid inheritance solely for code reuse.

## Quick checklist

1. What state does this object own, and how is valid state protected?
2. What responsibility does the class have?
3. Is the relationship truly **is-a**, or should it use composition?
4. Does the caller need a concrete type, or only an interface?
5. Is runtime polymorphism useful, or would a simpler function or template work?

## Related topics

- [Design principles](../Principles/README.md)
- [SOLID principles](../Principles/Solid/README.md)
- [Design patterns](../DesignPatterns/README.md)
- [LLD examples](../Examples/README.md)
