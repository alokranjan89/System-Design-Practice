# Factory Method: Quick Reference

Factory Method defines a creation operation in a creator interface and lets concrete creators choose which product to instantiate.

```text
Client -> Creator::createProduct() -> ConcreteCreator
                                      returns Product
```

| Role | Responsibility |
|---|---|
| Product | Common interface of created objects |
| Concrete product | Object that provides the actual behavior |
| Creator | Declares the factory method and uses the product |
| Concrete creator | Overrides the factory method to choose a product |

## Choose the factory style

| Style | Creation approach | Use when |
|---|---|---|
| Simple Factory | One function selects among products | Creation is small and centralized |
| Factory Method | Subclasses choose a product | Different creator types need different products |
| Abstract Factory | One factory creates related products | Products must come from a consistent family |

Factory Method is not automatically better as the number of products grows. It also adds creator classes and is useful when variation in creation belongs in those creator types.

## In this repository

- [`factory_method.cpp`](factory_method.cpp) shows Factory Method.
- [`README.md`](README.md) compares it with Simple Factory and Abstract Factory.

Trace which concrete creator is selected, which product it returns, and which interface the client uses. Compile `factory_method.cpp` from this folder using the command in the parent README.
