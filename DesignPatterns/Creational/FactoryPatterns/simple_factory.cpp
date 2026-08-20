/*
================================================================================
SIMPLE FACTORY PATTERN - DETAILED REVISION NOTES
================================================================================

DEFINITION:
- Simple Factory is a Creational Design Pattern that provides a factory method 
  to create objects without specifying the exact classes of the objects to create.
- It encapsulates object creation logic in a single factory method.

KEY COMPONENTS:
1. Abstract/Base Class (Product): Vehicle
   - Defines common interface for all products
   - Uses virtual functions for method overriding
   
2. Concrete Classes (Concrete Products): Car, Bike, Truck
   - Implement the abstract interface
   - Provide specific implementations for the abstract methods
   
3. Factory Class: vehicleFactory
   - Contains static factory method
   - Decides which concrete class to instantiate based on input
   - Centralizes object creation logic

ADVANTAGES:
✓ Encapsulation: Object creation logic is hidden from client code
✓ Centralized: All creation logic in one place (easy to modify)
✓ Loose Coupling: Client doesn't depend on concrete classes
✓ Easy Maintenance: Changes to creation logic only affect factory
✓ Flexibility: Easy to add new types without changing client code

DISADVANTAGES:
✗ Factory class can become too large with many product types
✗ Still some coupling to factory class
✗ Not a true factory pattern (doesn't follow OOP principles strictly)
✗ Violates Single Responsibility Principle if factory becomes complex

WHEN TO USE:
- When object creation is complex or needs logic
- When there are multiple object types to choose from
- When you want to decouple object creation from usage
- Simple scenarios (not suitable for complex hierarchies)

================================================================================
*/

#include <iostream>
using namespace std;

// ABSTRACT BASE CLASS (PRODUCT)
// ─────────────────────────────────────────────────────────────────────────────
// Purpose: Define a common interface for all vehicle types
// Benefits: Allows polymorphic behavior through pointers/references
class Vehicle
{
public:
    // Pure virtual function - all subclasses MUST implement this
    // This is the contract that all vehicles must follow
    virtual void drive() = 0;

    Vehicle() {} // Default constructor

    // Virtual destructor - IMPORTANT for proper cleanup when deleting derived objects
    // Without it, only base class destructor is called, leading to memory leaks
    virtual ~Vehicle() {}
};

// CONCRETE PRODUCT 1: Car
// ─────────────────────────────────────────────────────────────────────────────
// Implements the Vehicle interface
// Each concrete class represents a specific product type
class Car : public Vehicle
{
public:
    // Override keyword ensures we're overriding the base class virtual function
    // Compiler will error if the signature doesn't match
    void drive() override
    {
        cout << "Driving Car\n";
    }
};

// CONCRETE PRODUCT 2: Bike
// ─────────────────────────────────────────────────────────────────────────────
class Bike : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Bike\n";
    }
};

// CONCRETE PRODUCT 3: Truck
// ─────────────────────────────────────────────────────────────────────────────
class Truck : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Truck\n";
    }
};

// FACTORY CLASS
// ═════════════════════════════════════════════════════════════════════════════
// Purpose: Encapsulate all object creation logic in a single location
// 
// FACTORY METHOD PATTERN ELEMENTS:
// 1. Static Method: Allows calling without instantiating the factory
// 2. Single Responsibility: Only responsible for object creation
// 3. Decision Logic: Uses parameter to decide which object to create
// 
// FLOW:
// Client → Calls factory with choice → Factory analyzes choice → 
// Factory creates appropriate object → Returns pointer to base class
// ═════════════════════════════════════════════════════════════════════════════
class vehicleFactory
{
public:
    // Static method - can be called without creating factory instance
    // Returns pointer to Vehicle (base class) - allows polymorphism
    // Takes int parameter (choice) to determine which type to create
    static Vehicle *createVehicle(int choice)
    {
        // CHOICE 1: Create Car
        if (choice == 1)
            return new Car();  // new returns pointer, allocated on heap

        // CHOICE 2: Create Bike
        if (choice == 2)
            return new Bike();

        // CHOICE 3: Create Truck
        if (choice == 3)
            return new Truck();

        // DEFAULT: Invalid choice returns nullptr (null pointer)
        // IMPORTANT: Client must check for nullptr before using
        return nullptr;
    }
};

// MAIN FUNCTION - CLIENT CODE
// ═════════════════════════════════════════════════════════════════════════════
// EXECUTION FLOW:
// 1. User provides choice
// 2. Factory creates appropriate object based on choice
// 3. Client calls methods through base class pointer (polymorphism)
// 4. Memory is properly freed
//
// KEY BENEFITS IN THIS EXAMPLE:
// ✓ Client doesn't know about Car, Bike, or Truck classes
// ✓ Client only depends on Vehicle interface
// ✓ Adding new vehicle type only requires:
//   a) Create new class inheriting from Vehicle
//   b) Add case in factory method
// ✓ No changes needed in main() when adding new types
// ═════════════════════════════════════════════════════════════════════════════
int main()
{
    int choice;
    // Get user input to decide which vehicle type to create
    cin >> choice;

    // Call factory method - client gets a Vehicle pointer
    // Actual object type is hidden from client
    // This is called "polymorphism through factory"
    Vehicle *vehicle = vehicleFactory::createVehicle(choice);
    
    // ALWAYS check if factory returned valid object
    if (vehicle)
    {
        // Call drive() method - actual method depends on object type
        // If Car: prints "Driving Car"
        // If Bike: prints "Driving Bike"
        // If Truck: prints "Driving Truck"
        // This is DYNAMIC DISPATCH (runtime polymorphism)
        vehicle->drive();
        
        // MEMORY MANAGEMENT: Delete memory allocated by new
        // Virtual destructor ensures proper cleanup of derived class
        delete vehicle;
        
        // BEST PRACTICE: Set pointer to nullptr after delete
        // vehicle = nullptr;  // (optional but recommended)
    }
    else
    {
        // Handle invalid choice
        cout << "Invalid choice! Please select 1, 2, or 3.\n";
    }
    
    // Program ends here
    return 0;
}

/*
================================================================================
REVISION Q&A - COMMON INTERVIEW QUESTIONS & ANSWERS
================================================================================

Q1: What is the Simple Factory Pattern?
────────────────────────────────────────────────────────────────────────────────
A: A creational pattern that encapsulates object creation logic in a factory 
   method. Instead of clients creating objects directly using 'new', they request 
   objects from the factory, which decides which concrete class to instantiate.

Q2: Why use virtual destructors?
────────────────────────────────────────────────────────────────────────────────
A: When deleting a derived class object through a base class pointer, the virtual 
   destructor ensures the ENTIRE cleanup chain is executed (derived → base). 
   Without it, only the base destructor runs, causing memory leaks.
   
   Example:
   Vehicle *v = new Car();
   delete v;  // Calls Car::~Car() THEN Vehicle::~Vehicle() ✓ (with virtual)
              // Calls only Vehicle::~Vehicle() ✗ (without virtual)

Q3: What does 'override' keyword do?
────────────────────────────────────────────────────────────────────────────────
A: It's a compiler check that ensures:
   1. The function signature matches the virtual function in base class
   2. The base class actually has a virtual function to override
   3. If mismatch, compiler throws error (prevents subtle bugs)
   
   Without override:
   void drive()      // Might create new function, not override ✗
   
   With override:
   void drive() override  // Compiler verifies it's overriding ✓

Q4: Why return base class pointer instead of concrete class?
────────────────────────────────────────────────────────────────────────────────
A: LOOSE COUPLING - Client code:
   ✓ Only depends on Vehicle interface
   ✓ Doesn't know about Car, Bike, or Truck
   ✓ Works even if new vehicle types are added
   
   This enables:
   - Easy testing (mock Vehicle subclasses)
   - Easy extension (add new types without modifying client)
   - Code stability (concrete classes are internal details)

Q5: What happens if we don't check 'if (vehicle)' before using it?
────────────────────────────────────────────────────────────────────────────────
A: If choice is invalid, factory returns nullptr.
   Calling methods on nullptr → SEGMENTATION FAULT (crash)
   
   Always check: if (vehicle) { ... }  ✓
   Never assume: vehicle->drive(); ✗ (Dangerous!)

Q6: How would you add a new vehicle type (e.g., Bus)?
────────────────────────────────────────────────────────────────────────────────
A: 1. Create new class:
      class Bus : public Vehicle {
          void drive() override { cout << "Driving Bus\n"; }
      };
   
   2. Add to factory:
      if (choice == 4)
          return new Bus();
   
   3. No changes needed in main() ✓

Q7: Simple Factory vs Factory Method vs Abstract Factory?
────────────────────────────────────────────────────────────────────────────────
A: 
   SIMPLE FACTORY:
   - Single factory method
   - Uses if-else logic
   - Good for simple scenarios
   - Violates Open-Closed Principle (need to modify factory for new types)
   
   FACTORY METHOD:
   - Each product family has own factory class
   - Factories implement common interface
   - Better for complex scenarios
   - Follows Open-Closed Principle
   
   ABSTRACT FACTORY:
   - Multiple related product families
   - Each factory creates family of products
   - Most complex, most flexible
   - For cross-platform or theme-based systems

Q8: Is Simple Factory a true design pattern?
────────────────────────────────────────────────────────────────────────────────
A: Technically NO - it's more of a programming idiom.
   True patterns (Factory Method, Abstract Factory) are more sophisticated.
   BUT it's practical for simple use cases and widely used in real code.

Q9: What are potential problems with this implementation?
────────────────────────────────────────────────────────────────────────────────
A: 1. FACTORY BLOAT: Many if-else blocks = hard to maintain
   2. VIOLATES OCP: Must modify factory to add types
   3. MAGIC NUMBERS: Choice value (1, 2, 3) has no meaning
   
   FIX: Use enums instead of int:
   enum VehicleType { CAR = 1, BIKE = 2, TRUCK = 3 };
   static Vehicle *createVehicle(VehicleType type) { ... }

Q10: Memory management considerations?
────────────────────────────────────────────────────────────────────────────────
A: 1. Factory uses new() → objects on heap → must use delete
   2. Virtual destructor needed → proper cleanup
   3. No nullptr assignment after delete → bad practice (ok without it)
   4. Consider using smart pointers (unique_ptr, shared_ptr) instead:
      
      static unique_ptr<Vehicle> createVehicle(int choice) {
          if (choice == 1) return make_unique<Car>();
          return nullptr;
      }
      
      Then NO manual delete needed! ✓

Q11: When should you NOT use Simple Factory?
────────────────────────────────────────────────────────────────────────────────
A: 1. Complex object hierarchies (use Abstract Factory)
   2. Creating many different object families (use Abstract Factory)
   3. When factory class becomes massive (refactor to Factory Method)
   4. When you need to defer object creation (use Factory Method)

Q12: Real-world examples?
────────────────────────────────────────────────────────────────────────────────
A: 1. Database connection factory (MySQL, PostgreSQL, SQLite)
   2. Document parser factory (PDF, DOC, XML)
   3. Payment method factory (Credit card, PayPal, Bitcoin)
   4. Operating system factory (Windows, Linux, macOS)
   5. Logger factory (Console, File, Database)

================================================================================
REVISION CHECKLIST - VERIFY YOUR UNDERSTANDING
================================================================================

□ Understand what virtual functions are and why they're needed
□ Know why virtual destructors are essential
□ Understand polymorphism (calling derived methods through base pointer)
□ Know why static factory method doesn't need object instantiation
□ Understand loose coupling and why it's important
□ Know when to return nullptr and how to handle it
□ Can explain how to add new types without modifying client code
□ Understand advantages and disadvantages of this pattern
□ Know difference between Simple Factory and other factory patterns
□ Can write exception-safe factory or use smart pointers
□ Understand memory management (new/delete/virtual destructors)

================================================================================
*/