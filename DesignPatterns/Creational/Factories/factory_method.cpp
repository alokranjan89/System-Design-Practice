/*
================================================================================
FACTORY METHOD PATTERN - DETAILED REVISION NOTES
================================================================================

DEFINITION:
- Factory Method is a Creational Design Pattern that creates objects through
  a hierarchy of factory classes, one for each concrete product type.
- Uses inheritance to defer object creation to subclasses.
- Also known as Virtual Constructor pattern.

KEY DIFFERENCE FROM SIMPLE FACTORY:
┌─────────────────────────────────────────────────────────────────────────────┐
│  SIMPLE FACTORY              │  FACTORY METHOD                              │
├──────────────────────────────┼────────────────────────────────────────────────┤
│ Single factory method        │ Each product has own factory class           │
│ Uses if-else logic           │ Uses inheritance/polymorphism                │
│ Factory class can get bloated │ Easy to scale (add new factory class)       │
│ Violates Open-Closed Pr.     │ Follows Open-Closed Principle (OCP)        │
│ Less flexible                │ More flexible                                │
│ Good for: 1-5 types         │ Good for: 5+ types                          │
│ Quick solution               │ Proper design pattern                       │
└──────────────────────────────┴────────────────────────────────────────────────┘

KEY COMPONENTS:
1. Product Interface (abstract): Vehicle
2. Concrete Products: Car, Bike, Truck
3. Creator Interface (abstract): VehicleFactory
4. Concrete Creators: CarFactory, BikeFactory, TruckFactory

ADVANTAGES:
✓ Follows Open-Closed Principle (OCP) - open for extension, closed for modification
✓ Scalable - easy to add new product types
✓ Better organization - each factory handles one product
✓ Reduced coupling - factories separate from products
✓ Single Responsibility - each factory does one thing
✓ Easy to test - can mock factories
✓ Follows Dependency Inversion Principle

DISADVANTAGES:
✗ More classes - code becomes more complex
✗ Overkill for simple scenarios (3-5 types)
✗ More code to write and maintain
✗ Steeper learning curve
✗ May reduce performance (more objects created)

WHEN TO USE:
- Multiple related product types (5+)
- When new types will be added in future
- When you need to follow SOLID principles
- When subclasses need to decide object creation
- When you want easy testing with mocks

================================================================================
*/

#include <iostream>
using namespace std;

// ==========================
// Product Interface
// ==========================
// PURPOSE: Define common interface for all vehicles
// BENEFITS: Enables polymorphism, allows clients to work with any Vehicle
class Vehicle {
public:
    // Pure virtual function - all vehicles must implement
    virtual void drive() = 0;

    // Virtual destructor for proper cleanup
    virtual ~Vehicle() {}
};

// ==========================
// Concrete Products (Concrete Creators' Products)
// ==========================
// Each concrete class represents a vehicle type
// These are what the concrete factories will create

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving Car" << endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Driving Bike" << endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() override {
        cout << "Driving Truck" << endl;
    }
};

/*
KEY INSIGHT: Notice we have NO Car/Bike/Truck creation logic here.
The concrete factories will handle that. This is SEPARATION OF CONCERNS.
*/

// ==========================
// Creator (Abstract Factory/Factory Interface)
// ==========================
// PURPOSE: Define interface for creating vehicles
// KEY POINT: Uses virtual method (Factory Method) for object creation
// This is the SECRET of the pattern - defers creation to subclasses
//
// PATTERN FLOW:
// 1. Client doesn't know which factory to use
// 2. Client gets a factory reference (base class pointer)
// 3. Client calls createVehicle() on factory
// 4. Actual implementation depends on concrete factory type
// 5. Concrete factory creates specific product
// 6. Product returned as Vehicle* pointer

class VehicleFactory {
public:
    // Factory Method - virtual, to be overridden by concrete factories
    // This is the KEY method that defines the factory method pattern
    // Returns a Vehicle pointer (base class) for polymorphism
    virtual Vehicle* createVehicle() = 0;

    // Virtual destructor for proper cleanup
    virtual ~VehicleFactory() {}
};

/*
WHY THIS DESIGN?
- Each concrete factory is responsible for creating one product type
- Factory interface defines the contract: "I create vehicles"
- Concrete implementations decide WHICH vehicle type to create
- Client code only knows about VehicleFactory interface
- New vehicle types can be added by creating new factory class (NO changes to client!)
*/

// ==========================
// Concrete Factories (Concrete Creators)
// ==========================
// Each concrete factory is responsible for creating ONE product type
// Benefits:
// 1. Single Responsibility - each factory does one thing
// 2. Easy to extend - add new factory for new product
// 3. No modifications to existing factories
// 4. Follows Open-Closed Principle (OCP)

class CarFactory : public VehicleFactory {
public:
    // This factory creates Cars
    // Returns Car instance as Vehicle* pointer
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
public:
    // This factory creates Bikes
    // Returns Bike instance as Vehicle* pointer
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory {
public:
    // This factory creates Trucks
    // Returns Truck instance as Vehicle* pointer
    Vehicle* createVehicle() override {
        return new Truck();
    }
};

/*
SCALABILITY EXAMPLE:
To add a new vehicle type (Bus):

1. Create concrete product:
   class Bus : public Vehicle {
       void drive() override { cout << "Driving Bus\n"; }
   };

2. Create concrete factory:
   class BusFactory : public VehicleFactory {
       Vehicle* createVehicle() override { return new Bus(); }
   };

3. No changes needed in client code! ✓

This is why Factory Method is BETTER than Simple Factory for scaling.
*/

// ==========================
// Client
// ==========================

int main() {

    int choice;

    cout << "========= Vehicle Factory =========" << endl;
    cout << "1. Car" << endl;
    cout << "2. Bike" << endl;
    cout << "3. Truck" << endl;
    cout << "Enter Choice : ";

    cin >> choice;

    VehicleFactory* factory = nullptr;

    // Decide which factory to use

    switch(choice)
    {
        case 1:
            // Create CarFactory and assign to VehicleFactory pointer
            // This is POLYMORPHISM through pointers
            factory = new CarFactory();
            break;

        case 2:
            // Create BikeFactory and assign to VehicleFactory pointer
            factory = new BikeFactory();
            break;

        case 3:
            // Create TruckFactory and assign to VehicleFactory pointer
            factory = new TruckFactory();
            break;

        default:
            cout << "Invalid Choice" << endl;
            return 0;
    }

    // ────────────────────────────────────────────────────────────────────────────────
    // THE MAGIC: Factory creates object through virtual method
    // ────────────────────────────────────────────────────────────────────────────────
    // factory->createVehicle() is a virtual method call
    // Actual method called depends on concrete factory type:
    // - If factory points to CarFactory → calls CarFactory::createVehicle()
    // - If factory points to BikeFactory → calls BikeFactory::createVehicle()
    // - If factory points to TruckFactory → calls TruckFactory::createVehicle()
    // 
    // This is DYNAMIC DISPATCH (runtime polymorphism)
    // Compiler doesn't know which method to call, runtime decides!
    // ────────────────────────────────────────────────────────────────────────────────

    Vehicle* vehicle = factory->createVehicle();

    // Use the vehicle through base class interface
    // Client doesn't know if it's Car, Bike, or Truck
    // Doesn't matter - it's a Vehicle and can drive()
    vehicle->drive();

    // ────────────────────────────────────────────────────────────────────────────────
    // Memory Cleanup (IMPORTANT!)
    // ────────────────────────────────────────────────────────────────────────────────
    // Both factory and vehicle allocated with new
    // Both must be deleted
    // Virtual destructors ensure proper cleanup chain
    // ────────────────────────────────────────────────────────────────────────────────

    delete vehicle;   // Calls Vehicle::~Vehicle() and derived destructor
    delete factory;   // Calls VehicleFactory::~VehicleFactory() and concrete destructor

    return 0;
}

/*
================================================================================
REVISION Q&A - COMMON INTERVIEW QUESTIONS & ANSWERS
================================================================================

Q1: What is Factory Method Pattern?
────────────────────────────────────────────────────────────────────────────────
A: Factory Method is a creational pattern that defines an interface for creating
   objects in a superclass, but lets subclasses decide which concrete class to
   instantiate. It uses inheritance to defer creation logic to subclasses.
   
   Key phrase: "Define creation interface, defer to subclasses"

Q2: How is Factory Method different from Simple Factory?
────────────────────────────────────────────────────────────────────────────────
A: 
   SIMPLE FACTORY:
   - One factory class with all creation logic
   - Uses if-else to decide which object to create
   - Violates Open-Closed Principle
   - Factory becomes bloated with many products
   - Adding new product requires modifying factory
   
   FACTORY METHOD:
   - Multiple factory classes (one per product)
   - Each factory creates one specific product
   - Follows Open-Closed Principle
   - Easy to scale (add factory for new product)
   - No modification to existing code needed

Q3: Why create separate factory for each product?
────────────────────────────────────────────────────────────────────────────────
A: It follows Single Responsibility Principle:
   - Each factory has ONE responsibility: create its product
   - Easy to test (mock each factory independently)
   - Easy to modify (change one factory without affecting others)
   - Easy to extend (add new factory without touching existing ones)
   - Better organization and maintainability

Q4: What is polymorphism in this pattern?
────────────────────────────────────────────────────────────────────────────────
A: Two levels of polymorphism:
   
   LEVEL 1: Factory Polymorphism
   VehicleFactory* factory = new CarFactory();  // Base pointer, derived object
   factory->createVehicle();  // Calls CarFactory::createVehicle()
   
   LEVEL 2: Product Polymorphism
   Vehicle* vehicle = factory->createVehicle();  // Base pointer, derived object
   vehicle->drive();  // Calls Car::drive(), Bike::drive(), or Truck::drive()

Q5: Can you add a new vehicle type without modifying existing code?
────────────────────────────────────────────────────────────────────────────────
A: Yes! This is the MAIN BENEFIT. To add Bus:
   
   // STEP 1: Create concrete product
   class Bus : public Vehicle {
       void drive() override { cout << "Driving Bus\n"; }
   };
   
   // STEP 2: Create concrete factory
   class BusFactory : public VehicleFactory {
       Vehicle* createVehicle() override { return new Bus(); }
   };
   
   // STEP 3: Use in main
   factory = new BusFactory();
   
   NO CHANGES to existing Car, Bike, Truck, CarFactory, BikeFactory, TruckFactory!
   This follows OPEN-CLOSED PRINCIPLE perfectly.

Q6: Why use base class pointers (VehicleFactory* and Vehicle*)?
────────────────────────────────────────────────────────────────────────────────
A: LOOSE COUPLING and SCALABILITY:
   - Client code doesn't depend on concrete classes
   - Can swap implementations at runtime
   - Easy to test (mock factories)
   - Works with any factory implementing interface
   - Adding new types doesn't break existing client code

Q7: Where does the factory decision (which factory to create) happen?
────────────────────────────────────────────────────────────────────────────────
A: In client code (main() in this example). In real applications:
   - Could come from configuration file
   - Could come from database
   - Could come from environment variables
   - Could come from user input (like in this example)
   - Could be delegated to a Service Locator or Dependency Injection
   
   The pattern doesn't prescribe WHERE this decision is made.

Q8: What's the purpose of virtual method createVehicle() in base factory?
────────────────────────────────────────────────────────────────────────────────
A: It's the "Factory Method" - the core of the pattern:
   - Defines contract: "All factories must create something"
   - Virtual allows each subclass to implement differently
   - Enables polymorphism (calling through base pointer)
   - Allows client to call createVehicle() without knowing concrete type

Q9: When should you use Factory Method over Simple Factory?
────────────────────────────────────────────────────────────────────────────────
A: Use Factory Method when:
   ✓ 5+ product types (starts getting complicated in Simple Factory)
   ✓ Products will be added in future
   ✓ Need to follow SOLID principles
   ✓ Want better testability
   ✓ Want better scalability
   
   Use Simple Factory when:
   ✓ Only 1-3 product types
   ✓ Products are unlikely to change
   ✓ Need quick, simple solution
   ✓ Codebase size is small

Q10: What about memory management?
────────────────────────────────────────────────────────────────────────────────
A: Both factory and product are allocated with new and must be deleted:
   
   delete vehicle;  // Deletes product
   delete factory;  // Deletes factory
   
   Virtual destructors ensure:
   - Derived destructors are called first
   - Then base destructors
   - Complete cleanup of all resources
   
   BETTER: Use smart pointers (unique_ptr, shared_ptr):
   unique_ptr<VehicleFactory> factory(new CarFactory());
   unique_ptr<Vehicle> vehicle(factory->createVehicle());
   Automatic cleanup when going out of scope

Q11: UML Structure - Creator and Product Hierarchies
================================================================

Creator/Factory Hierarchy:
   VehicleFactory (interface)
   |-- CarFactory
   |-- BikeFactory
   |-- TruckFactory

Product Hierarchy:
   Vehicle (interface)
   |-- Car
   |-- Bike
   |-- Truck

Relationship: Each factory creates one product type

Q12: Real-world examples?
================================================================

A: 1. Document creation (PDF, Word, Excel factories)
   2. Database drivers (MySQL, PostgreSQL, SQLite factories)
   3. Payment processors (Credit Card, PayPal, Bitcoin factories)
   4. UI frameworks (Button, TextField, CheckBox factories)
   5. Logging frameworks (Console, File, Database logger factories)
   6. Serialization (JSON, XML, Protobuf serializer factories)
   7. Image processing (PNG, JPEG, GIF image factories)

Q13: Pros and Cons?
================================================================

A: PROS:
[+] Follows Open-Closed Principle (extensible without modification)
[+] Single Responsibility (each factory has one job)
[+] Scalable (easy to add many types)
[+] Maintainable (organized structure)
[+] Testable (can mock factories)
[+] Flexible (easy to swap implementations)

CONS:
[-] More code (more classes to write)
[-] Overkill for simple scenarios
[-] Complexity (steeper learning curve)
[-] More objects created (performance impact)
[-] Harder to debug (more indirection)

Q14: How loose coupling works?
================================================================

Client only depends on interfaces, not implementations:

WITHOUT PATTERN (TIGHTLY COUPLED):
main() knows about: CarFactory, BikeFactory, TruckFactory, Car, Bike, Truck
Adding new type requires modifying main()

WITH PATTERN (LOOSELY COUPLED):
main() knows only about: VehicleFactory interface and Vehicle interface
Adding new type requires creating new classes, NO changes to main()

Dependencies flow: Concrete classes -> Abstract interfaces (Dependency Inversion)

Q15: Factory Method vs Abstract Factory?
================================================================

Use Factory Method when:
- One product family (vehicles, documents, etc.)
- Each type has its own factory
- Step-by-step extension with new factories

Use Abstract Factory when:
- Multiple related product families
- Need to create families together (modern + classic themes)
- Products must work together as a family

Example:
Factory Method: One Vehicle factory per type
Abstract Factory: One Theme factory for buttons AND windows together

================================================================================
REVISION CHECKLIST
================================================================================

[ ] Understand what Factory Method pattern is
[ ] Know difference between Simple Factory and Factory Method
[ ] Understand why separate factory per product
[ ] Know about two levels of polymorphism
[ ] Can explain adding new types without modifying existing code
[ ] Understand Open-Closed Principle
[ ] Know base class pointer benefits (loose coupling)
[ ] Understand virtual method dispatch
[ ] Know memory management with new/delete
[ ] Understand when to use vs Simple Factory
[ ] Know real-world examples
[ ] Can draw UML diagram  
[ ] Can answer all interview questions

================================================================================
*/
/*
   PROS:
   [+] Follows Open-Closed Principle (extensible without modification)
   [+] Single Responsibility (each factory has one job)
   [+] Scalable (easy to add many types)
   [+] Maintainable (organized structure)
   [+] Testable (can mock factories)
   [+] Flexible (easy to swap implementations)
   
   CONS:
   [-] More code (more classes to write)
   [-] Overkill for simple scenarios
   [-] Complexity (steeper learning curve)
   [-] More objects created (performance impact)
   [-] Harder to debug (more indirection)

Q14: How does this pattern promote loose coupling?
================================================================================
A: Client only depends on interfaces, not implementations:
   
   WITHOUT PATTERN (TIGHTLY COUPLED):
   main() -> knows about CarFactory, BikeFactory, TruckFactory, Car, Bike, Truck
   Adding new type requires modifying main()
   
   WITH PATTERN (LOOSELY COUPLED):
   main() -> only knows about VehicleFactory and Vehicle interfaces
   Adding new type requires creating new classes, NO changes to main()
   
   Dependencies flow: Concrete -> Abstract (Dependency Inversion)

Q15: When would you prefer Abstract Factory over Factory Method?
================================================================================
A: When you have MULTIPLE RELATED PRODUCT FAMILIES:
   
   FACTORY METHOD (one family):
   |- Vehicles: Car, Bike, Truck
   
   ABSTRACT FACTORY (multiple families):
   |- Modern theme:
   |  |- ModernButton, ModernTextField, ModernWindow
   |- Classic theme:
   |  |- ClassicButton, ClassicTextField, ClassicWindow
   
   Factory Method: One product per factory
   Abstract Factory: Multiple products per factory

================================================================================
REVISION CHECKLIST
================================================================================

[ ] Understand what Factory Method pattern is
[ ] Know difference between Simple Factory and Factory Method
[ ] Understand why separate factory per product
[ ] Know about two levels of polymorphism
[ ] Can explain adding new types without modifying existing code
[ ] Understand Open-Closed Principle
[ ] Know base class pointer benefits (loose coupling)
[ ] Understand virtual method dispatch
[ ] Know memory management with new/delete
[ ] Understand when to use vs Simple Factory
[ ] Know real-world examples
[ ] Can draw UML diagram
[ ] Can answer all interview questions

================================================================================
*/
/*
A: Client only depends on interfaces, not implementations:
   
   WITHOUT PATTERN (TIGHTLY COUPLED):
   main() → knows about CarFactory, BikeFactory, TruckFactory, Car, Bike, Truck
   Adding new type requires modifying main()
   
   WITH PATTERN (LOOSELY COUPLED):
   main() → only knows about VehicleFactory and Vehicle interfaces
   Adding new type requires creating new classes, NO changes to main()
   
   Dependencies flow: Concrete → Abstract (Dependency Inversion)

Q15: When would you prefer Abstract Factory over Factory Method?
────────────────────────────────────────────────────────────────────────────────
A: When you have MULTIPLE RELATED PRODUCT FAMILIES:
   
   FACTORY METHOD (one family):
   ├─ Vehicles: Car, Bike, Truck
   
   ABSTRACT FACTORY (multiple families):
   ├─ Modern theme:
   │  ├─ ModernButton, ModernTextField, ModernWindow
   ├─ Classic theme:
   │  ├─ ClassicButton, ClassicTextField, ClassicWindow
   
   Factory Method: One product per factory
   Abstract Factory: Multiple products per factory

================================================================================
REVISION CHECKLIST
================================================================================

□ Understand what Factory Method pattern is
□ Know difference between Simple Factory and Factory Method
□ Understand why separate factory per product
□ Know about two levels of polymorphism
□ Can explain adding new types without modifying existing code
□ Understand Open-Closed Principle
□ Know base class pointer benefits (loose coupling)
□ Understand virtual method dispatch
□ Know memory management with new/delete
□ Understand when to use vs Simple Factory
□ Know real-world examples
□ Can draw UML diagram
□ Can answer all interview questions

================================================================================
*/
