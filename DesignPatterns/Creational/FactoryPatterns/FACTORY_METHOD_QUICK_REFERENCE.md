# Factory Method Pattern - Quick Reference Card

## 🎯 Pattern at a Glance

```
WHAT: Each product type has its own factory class with virtual creation method
WHY: Better scalability and follows Open-Closed Principle (no modification needed)
WHEN: 5+ product types, will add more in future, need clean architecture
HOW: Define factory interface, create concrete factory for each product type
```

---

## 📐 UML-Style Structure

```
┌──────────────────────┐
│  <<interface>>       │
│  VehicleFactory      │  ← Abstract Factory (Creator)
│ ──────────────────── │
│ +createVehicle()    │  ← Factory Method (virtual)
└──────────────────────┘
        △
   ┌────┼────┐
   │    │    │
┌──┴──┐┌──┴──┐┌──┴───┐
│CarF ││BikeF││TruckF│  ← Concrete Factories (Concrete Creators)
└─────┘└─────┘└──────┘
  │      │       │
  │      │       └──────────┐
  │      └─────────┐        │
  │               │        │
  └──────┬────────┴────┬───┘
         │             │
  ┌──────────────────────────┐
  │  <<interface>>           │
  │  Vehicle                 │  ← Abstract Product
  │ ──────────────────────── │
  │ +drive()                 │
  └──────────────────────────┘
         △
    ┌────┼────┐
    │    │    │
┌───┴──┐┌───┴──┐┌───┴───┐
│ Car  ││ Bike  ││ Truck │  ← Concrete Products
└──────┘└───────┘└───────┘
```

---

## 💻 Code Template

### Abstract Factory (Creator)
```cpp
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;  // Factory Method
    virtual ~VehicleFactory() {}
};
```

### Concrete Factories
```cpp
class CarFactory : public VehicleFactory {
    Vehicle* createVehicle() override { return new Car(); }
};

class BikeFactory : public VehicleFactory {
    Vehicle* createVehicle() override { return new Bike(); }
};
```

### Products (same as always)
```cpp
class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    void drive() override { cout << "Driving Car\n"; }
};
```

### Client Code
```cpp
VehicleFactory* factory = nullptr;

if (choice == 1)
    factory = new CarFactory();
else if (choice == 2)
    factory = new BikeFactory();

Vehicle* vehicle = factory->createVehicle();
vehicle->drive();

delete vehicle;
delete factory;
```

---

## 🔑 Key Concepts

| Concept | Meaning |
|---------|---------|
| **Factory Method** | Virtual method in base factory that creates products |
| **Concrete Factory** | Each product type has its own factory class |
| **Polymorphism** | Two levels: factory polymorphism + product polymorphism |
| **Open-Closed** | Open for extension (add factories), closed for modification (don't change existing) |
| **Single Responsibility** | Each factory responsible for creating ONE type |
| **Loose Coupling** | Client depends on interfaces, not implementations |

---

## ⚙️ How It Works (Step by Step)

```
1. Client decides: switch(choice) { case 1: factory = new CarFactory(); }
                                                   ↓
2. Factory instantiated: factory now points to CarFactory instance
                                                   ↓
3. Client calls: Vehicle* vehicle = factory->createVehicle()
                                                   ↓
4. Virtual dispatch: Calls CarFactory::createVehicle() (not VehicleFactory!)
                                                   ↓
5. Factory creates: return new Car();
                                                   ↓
6. Client receives: Vehicle* pointing to Car object
                                                   ↓
7. Client uses: vehicle->drive() → calls Car::drive()
                                                   ↓
8. Cleanup: delete vehicle; delete factory;
```

---

## ✅ DO's

- ✓ Create one factory class per product type
- ✓ Use virtual method for factory method
- ✓ Use base class pointers for loose coupling
- ✓ Check for nullptr after creation
- ✓ Delete both factory and product
- ✓ Use virtual destructors
- ✓ Add new types by creating new factory class
- ✓ Keep factory responsibilities single

---

## ❌ DON'Ts

- ✗ Put all creation logic in one factory (use Simple Factory then)
- ✗ Use concrete factory pointers (defeats purpose)
- ✗ Forget to delete factory object
- ✗ Use without virtual destructor
- ✗ Mix factory creation with product creation logic
- ✗ Make factory too complex
- ✗ Violate single responsibility principle

---

## 🔄 Factory Method vs Simple Factory vs Abstract Factory

```
┌──────────────────────────────────────────────────────────────────────────┐
│                  WHEN TO USE WHICH PATTERN                              │
├──────────────────────────┬──────────────────────┬──────────────────────┤
│ SIMPLE FACTORY           │ FACTORY METHOD       │ ABSTRACT FACTORY     │
├──────────────────────────┼──────────────────────┼──────────────────────┤
│ 1-5 product types        │ 5+ product types     │ Product families     │
│ Quick solution           │ Scalable             │ Most flexible        │
│ Single factory method    │ One factory per type │ Multiple factories   │
│ If-else logic            │ Inheritance          │ Inheritance          │
│ Violates OCP             │ Follows OCP          │ Follows OCP          │
│ Modify factory to extend │ Add new factory      │ Add new factory      │
│ Easy to understand       │ Moderate complexity  │ Most complex         │
│ Less code                │ More code            │ Most code            │
│                          │                      │                      │
│ Examples:                │ Examples:            │ Examples:            │
│ Database->create()       │ MySQLFactory         │ UIThemeFactory       │
│                          │ PostgreSQLFactory    │ (Modern + Classic)   │
└──────────────────────────┴──────────────────────┴──────────────────────┘
```

---

## 🐛 Common Mistakes & Fixes

### Mistake 1: Single Bloated Factory
```cpp
// ❌ WRONG - defeats the purpose!
class VehicleFactory {
public:
    Vehicle* createVehicle(string type) {
        if (type == "car") return new Car();
        if (type == "bike") return new Bike();
        // This is just Simple Factory!
    }
};

// ✓ CORRECT - separate factories
class CarFactory : public VehicleFactory { /* ... */ };
class BikeFactory : public VehicleFactory { /* ... */ };
```

### Mistake 2: Not Deleting Factory
```cpp
// ❌ WRONG - memory leak!
VehicleFactory* factory = new CarFactory();
Vehicle* v = factory->createVehicle();
v->drive();
delete v;
// factory never deleted!

// ✓ CORRECT
VehicleFactory* factory = new CarFactory();
Vehicle* v = factory->createVehicle();
v->drive();
delete v;
delete factory;  // Don't forget!
```

### Mistake 3: Forgetting Virtual Destructor
```cpp
// ❌ WRONG
class VehicleFactory {
    ~VehicleFactory() {}  // NOT virtual!
};

// ✓ CORRECT
class VehicleFactory {
    virtual ~VehicleFactory() {}
};
```

### Mistake 4: Using Concrete Pointers
```cpp
// ❌ WRONG - defeats purpose
CarFactory* factory = new CarFactory();
factory->createVehicle();  // Tightly coupled

// ✓ CORRECT - loose coupling
VehicleFactory* factory = new CarFactory();
factory->createVehicle();  // Works with any factory
```

---

## 🎓 Quick Q&A (One-Liners)

| Q | A |
|---|---|
| Factory Method = ? | One factory per product, uses inheritance, follows OCP |
| Diff from Simple Factory? | Multiple factories vs single factory; inheritance vs if-else |
| Why not one factory? | Violates Single Responsibility, hard to scale |
| When to use? | 5+ types, future extensibility, need SOLID principles |
| Where is factory decision? | In client code (switch/if or config) |
| Can add new type? | Yes! Create factory + product, zero changes to existing |
| Real example? | Database drivers (MySQLFactory, PostgreSQLFactory) |
| UML has? | Creator + Concrete Creator + Product + Concrete Product |
| Memory management? | Delete both factory and product |
| Vs Abstract Factory? | FM: one family; AF: multiple families |

---

## 📊 Pros & Cons Summary

### Pros
1. **Open-Closed Principle** ✓
   - No modification needed, just extend
   - Add new types without changing code

2. **Single Responsibility** ✓
   - Each factory does one thing
   - Easier maintenance

3. **Scalable** ✓
   - Easy to add 10, 50, 100 types
   - Each gets its own factory class

4. **Organized** ✓
   - Clear structure
   - Easy to navigate codebase

5. **Testable** ✓
   - Can mock each factory independently
   - Good for unit testing

6. **Flexible** ✓
   - Easy to swap implementations
   - Runtime decisions

### Cons
1. **More Code** ✗
   - Need factory class for each type
   - 3 vehicles = 6 classes (3 + 3 factories)

2. **Complexity** ✗
   - More classes to manage
   - Steeper learning curve

3. **Overkill for Small Projects** ✗
   - Simpler designs work better
   - Factory Method is overengineering

4. **Slight Performance Hit** ✗
   - More object creation
   - Virtual function calls

5. **Harder to Debug** ✗
   - More indirection
   - Harder to trace execution

---

## 🚀 Evolution Path

```
Project starts small
    ↓
Use Simple Factory (3-5 types)
    ↓
More types needed (5+) or SOLID required
    ↓
Refactor to Factory Method
    ↓
Multiple product families needed
    ↓
Refactor to Abstract Factory
    ↓
Very complex systems
    ↓
Consider Service Locator or DI Container
```

---

## 🔍 Interview Power Phrases

1. **"Factory Method is a true design pattern unlike Simple Factory"** - Shows knowledge of patterns
2. **"Follows Open-Closed Principle - open for extension, closed for modification"** - Shows SOLID knowledge
3. **"Each factory has single responsibility - creating one type"** - Shows SRP knowledge
4. **"Two levels of polymorphism - factory and product"** - Shows deep understanding
5. **"No modifications needed to add new types"** - Shows scalability knowledge
6. **"Uses inheritance to defer creation to subclasses"** - Shows pattern definition knowledge
7. **"Better than Simple Factory for 5+ types"** - Shows pattern selection knowledge

---

## ⏱️ Time Complexity

- Factory selection: **O(1)** (direct instantiation)
- Factory method call: **O(1)** (virtual dispatch)
- Product creation: **O(1)** (constructor)
- **Total: O(1)** (constant time)

---

## 📚 Key Takeaways

1. **One factory per product type** - That's the pattern
2. **Follows Open-Closed Principle** - Main advantage
3. **More code but more maintainable** - Trade-off
4. **Better for scalable systems** - Good for growing codebases
5. **Two-level polymorphism** - Both factory and product
6. **Clean architecture** - Clear separation of concerns
7. **True design pattern** - Not just an idiom like Simple Factory
8. **Use for 5+ types** - Overkill for smaller projects

---

## 🎯 When Ready for Interview

- [ ] Can explain pattern in 2 minutes
- [ ] Can code from memory (factory + product + client)
- [ ] Can answer 15 Q&A questions
- [ ] Can draw UML diagram
- [ ] Can compare with Simple Factory
- [ ] Can compare with Abstract Factory
- [ ] Can give 3+ real-world examples
- [ ] Can identify antipatterns
- [ ] Can discuss memory management
- [ ] Can suggest improvements

---

**Last Updated:** 2025
**Complexity Level:** Intermediate (more complex than Simple Factory)
**Interview Difficulty:** Medium-High (commonly asked)
**Status:** Ready for Interview Prep ✓
