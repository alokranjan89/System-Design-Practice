# Abstraction

Abstraction exposes what a caller needs while hiding how it is done. For example, a caller can use `PaymentMethod::pay()` without knowing the details of card processing.

In C++, abstraction can come from a simple public API, an abstract class, or a concept/template, depending on the design. An abstract class can define an interface:

```cpp
class PaymentMethod {
public:
    virtual void pay(int cents) = 0;
    virtual ~PaymentMethod() = default;
};
```

## Why it helps

Callers depend on the operation they need instead of the implementation details. This can make implementations easier to replace and code easier to understand.

## Remember

Use an abstraction when it makes the caller's job simpler or separates a changeable implementation. An interface with only one implementation and no real boundary may add needless complexity.
