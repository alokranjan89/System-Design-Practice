# Inheritance

Inheritance models an **is-a** relationship: a derived type can be used where its base type is expected. Use public inheritance only when the derived type can honor the base type's behavior. Inheritance creates coupling, so prefer composition when an object simply needs to use or own another object.

```cpp
class Vehicle {
public:
    explicit Vehicle(int wheels) : wheels(wheels) {}
    int getWheels() const { return wheels; }
private:
    int wheels;
};

class Bicycle : public Vehicle {
public:
    Bicycle() : Vehicle(2) {}
};
```

Here, `Bicycle` is a `Vehicle` and inherits its wheel-count behavior.

## Use inheritance when

- The derived type truly is a subtype of the base type.
- It preserves the expectations and behavior of the base type.
- Shared behavior or a common interface belongs in the base type.

## Prefer composition when

An object **has** another object or delegates work to it. For example, a `Car` has an `Engine`; a car is not an engine.
