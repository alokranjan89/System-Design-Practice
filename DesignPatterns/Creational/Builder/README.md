# Builder Pattern

## Overview
The Builder pattern separates the construction of a complex object from its representation. It allows you to build different configurations of an object step by step while keeping construction code readable and maintainable.

In this example, the `Computer` class represents the product and `ComputerBuilder` provides a fluent interface to set optional properties before creating the final `Computer` object.

## Key Concepts
- Product: `Computer` is the object being built.
- Builder: `ComputerBuilder` assembles the product using setter methods.
- Fluent interface: Each setter returns `*this` so calls can be chained.
- Final build step: `build()` returns the completed `Computer`.

## Benefits
- Makes it easy to construct objects with many optional fields.
- Prevents constructors with long parameter lists.
- Improves readability of object creation code.
- Enables immutable or partially set objects when adapted for that use.

## Example Walkthrough
1. Create a builder instance: `ComputerBuilder()`.
2. Chain setter calls:
   - `setCPU("Intel i9")`
   - `setRAM(32)`
   - `setSSD(1000)`
   - `setGPU(true)`
   - `setRGB(true)`
   - `setWiFi(true)`
3. Call `build()` to get the final `Computer` object.

## When to Use
- When constructing objects with many optional parameters.
- When you want to avoid constructors with many arguments.
- When you need a readable, step-by-step construction process.
- When you want to support multiple product configurations without many constructors.

## Notes on the Implementation
- The builder stores a `Computer` instance internally.
- Each configuration method updates the internal product and returns the builder.
- The `build()` method returns the configured `Computer`.
- This implementation is simple and works well for demonstration, but a production version may also validate required fields or make the product immutable.

## Running the Example
Compile and run the example from the `Builder` folder:

```powershell
cd "System Design\DesignPatterns\Creational\Builder"
g++ -std=c++17 -Wall builder.cpp -o builder.exe
./builder.exe
```
