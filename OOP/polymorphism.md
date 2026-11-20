# Polymorphism

Polymorphism lets callers use a common interface while different types provide different behavior.

## Runtime polymorphism

In C++, runtime polymorphism uses virtual functions and typically a base pointer or reference. `override` asks the compiler to verify that a function overrides a base function. A base class used polymorphically should generally have a virtual destructor.

Given the `Shape` and `Circle` types in [polymorphism.cpp](polymorphism.cpp), a function can work with any shape:

```cpp
void printArea(const Shape& shape) {
    std::cout << shape.area(); // calls Circle::area for a Circle
}
```

The call to `area()` is selected at runtime based on the actual object type.

## Compile-time polymorphism

C++ also supports compile-time polymorphism through templates and overloaded functions. The compiler selects a matching implementation when compiling the program.

## Remember

Use polymorphism when code should work with multiple types through a shared interface. If there is only one type and no expected variation, a simple function may be clearer.
