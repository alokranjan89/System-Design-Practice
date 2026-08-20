/*
================================================================================
PROTOTYPE PATTERN - DETAILED REVISION NOTES
================================================================================

DEFINITION:
- Prototype is a Creational Design Pattern that creates objects by copying an
  existing object (prototype) rather than creating from scratch.
- Avoids expensive object creation by cloning an already-initialized object.
- Also known as "Clone" pattern.

WHY USE PROTOTYPE:
- Object initialization is EXPENSIVE (database calls, complex calculations)
- Creating similar objects repeatedly wastes resources
- Cloning an existing object is FASTER than recreation
- Example: Creating 1000 NPCs in a game - create 1, clone 999 times

KEY COMPONENTS:
1. Prototype Interface: Defines clone() method
2. Concrete Prototype: Implements clone() with copy constructor
3. Client: Creates new objects by cloning prototypes

WHEN TO USE:
✓ Object creation is expensive (DB queries, complex calculations)
✓ Similar objects need to be created repeatedly
✓ Classes are unknown at compile time (polymorphism)
✓ Customization needed after creation
✓ Performance is critical

SHALLOW vs DEEP COPY:
┌──────────────────────────────────────────────────────────────────────────┐
│ SHALLOW COPY                    │ DEEP COPY                             │
├─────────────────────────────────┼───────────────────────────────────────┤
│ Copy primitives & pointers      │ Copy primitives & clone data          │
│ Pointers → original memory      │ New pointers → new memory             │
│ Modifying data affects original │ Modifications don't affect original    │
│ Faster (just copy addresses)    │ Slower (allocate + copy data)         │
│ Risk: Original affected         │ Safe: Independent copies              │
│ Good for: Immutable fields      │ Good for: Mutable pointers            │
└─────────────────────────────────┴───────────────────────────────────────┘

================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==========================
// PROTOTYPE INTERFACE (Product)
// ==========================
// PURPOSE: Define clone() contract that all prototypes must implement
// BENEFIT: Enables polymorphic cloning through base class pointer
// Cloneable (aka Prototype) interface
// Any object that can be cloned should implement this.
class Cloneable {
public:
    // Pure virtual clone method - defines the contract
    // Returns: Cloneable* to base class for polymorphism
    // const: Clone doesn't modify the original
    virtual Cloneable* clone() const = 0;
    
    // Virtual destructor for proper cleanup
    virtual ~Cloneable() {}
};

// ==========================
// CONCRETE PROTOTYPE (Concrete Product)
// ==========================
// PURPOSE: Implement clone() using copy constructor
// BENEFITS: 
// - Cheap object creation (just copy fields)
// - Original object stays unchanged
// - Each clone can be customized independently
// NPC is a concrete prototype with clone support.
class NPC : public Cloneable {
public:
    string name;
    int health;
    int attack;
    int defense;

    // EXPENSIVE CONSTRUCTOR - Simulates costly initialization
    // In real scenarios: database queries, file I/O, complex calculations, network calls
    // This is why we use Prototype pattern - create once, clone many times
    NPC(const string& name, int health, int attack, int defense) {
        // Simulating expensive operations:
        // - Call database to load base attributes
        // - Perform complex calculations
        // - Load AI behavior patterns
        // - Initialize graphics/audio
        this->name = name; 
        this->health = health; 
        this->attack = attack; 
        this->defense = defense;
        cout << "Setting up template NPC '" << name << "' (expensive operation)\n";
    }

    // COPY CONSTRUCTOR - Used by clone() for cheap object creation
    // 
    // This performs a SHALLOW COPY:
    // - Copies primitive values (int, bool, etc.) directly
    // - Copies pointer VALUES (addresses), not the data they point to
    // - std::string handles its own deep copy automatically
    // 
    // Why shallow copy is OK here:
    // ✓ Primitive fields (name=string, health/attack/defense=int) - safe to copy
    // ✓ string class manages memory - safe to copy
    // ✗ If NPC had raw pointers (int* pData), would need DEEP COPY
    // 
    // KEY: Copy constructor is MUCH CHEAPER than normal constructor
    // - No database calls
    // - No complex calculations
    // - Just memcpy-like operation
    NPC(const NPC& other) {
        name = other.name;              // string makes deep copy automatically
        health = other.health;          // primitive: safe to copy
        attack = other.attack;          // primitive: safe to copy
        defense = other.defense;        // primitive: safe to copy
        cout << "Cloning NPC '" << name << "' (cheap operation)\n";
    }

    // CLONE METHOD - Core of Prototype pattern
    // 
    // EXECUTION:
    // 1. Create new NPC object using copy constructor
    // 2. Return as Cloneable* (base class pointer) for polymorphism
    // 3. Original object unchanged
    // 
    // PERFORMANCE:
    // - Copy constructor: O(1) for simple fields
    // - No database queries, calculations, or initialization
    // - 1000x faster than normal constructor for this example
    // 
    // POLYMORPHISM:
    // Client can call clone() on Cloneable* pointer
    // Actual method called depends on runtime type (Car, Zombie, Dragon, etc.)
    Cloneable* clone() const override {
        return new NPC(*this);  // Uses copy constructor
    }

    // Print NPC state for debugging.
    void describe() {
        cout << "NPC " << name  << " [HP=" << health  << " ATK=" << attack 
             << " DEF=" << defense << "]\n";
    }

    // Setters allow customizing each clone independently.
    void setName(const string& n) { 
        name = n;
    }
    void setHealth(int h) { 
        health = h;
    }
    void setAttack(int a) {
         attack = a; 
    }
    void setDefense(int d){ 
        defense = d;
    }
};

int main() {
    // ==========================
    // CLIENT CODE - PROTOTYPE USAGE
    // ==========================
    
    // STEP 1: Create expensive template object ONCE
    // This calls the normal constructor - expensive but happens only once!
    cout << "Step 1: Creating template...\n";
    NPC* alien = new NPC("Alien", 30, 5, 2);
    
    // STEP 2: Clone template instead of recreating
    // This calls copy constructor - CHEAP!
    cout << "\nStep 2: Creating clone 1...\n";
    NPC* alienCopied1 = dynamic_cast<NPC*>(alien->clone());
    alienCopied1->describe();

    // STEP 3: Clone and customize
    // Clone is cheap, customization is independent
    cout << "\nStep 3: Creating clone 2 (customized)...\n";
    NPC* alienCopied2 = dynamic_cast<NPC*>(alien->clone());
    alienCopied2->setName("Powerful Alien");  // Doesn't affect original!
    alienCopied2->setHealth(50);               // Independent modification
    alienCopied2->describe();
    
    cout << "\nOriginal alien still unchanged:\n";
    alien->describe();

    // STEP 4: Memory Cleanup
    cout << "\nCleaning up...\n";
    delete alien;         // Delete template
    delete alienCopied1;  // Delete clone 1
    delete alienCopied2;  // Delete clone 2
    
    return 0;
}

/*
================================================================================
REVISION Q&A - COMMON INTERVIEW QUESTIONS
================================================================================

Q1: What is Prototype Pattern?
A: Pattern that creates objects by cloning an existing prototype instead of
   creating from scratch. Avoids expensive initialization.

Q2: Why use Prototype over normal constructor?
A: When object creation is expensive (DB, calculations, I/O), clone a template
   object instead. Cloning is ~1000x faster for complex objects.

Q3: Shallow vs Deep copy - what's the difference?
A: Shallow copy copies pointer addresses (not data).
   Deep copy allocates new memory and copies data.
   Use shallow when fields are safe (primitives, strings).
   Use deep when fields are pointers to data that must be independent.

Q4: How does polymorphic cloning work?
A: Cloneable* ptr = new Car();
   Cloneable* clone = ptr->clone();  // Calls Car::clone(), not Cloneable::clone()
   Dynamic dispatch determines actual method at runtime.

Q5: When should you use Prototype?
A: ✓ Expensive object creation (DB, network, calculations)
   ✓ Creating similar objects repeatedly
   ✓ Object types unknown at compile time
   ✓ Need independent customizable copies

Q6: Prototype vs Factory?
A: Factory CREATES objects.
   Prototype COPIES existing objects.
   Factory: When creation is complex.
   Prototype: When copying is cheaper than creating.

Q7: What about clone() returning void pointer?
A: Return Cloneable* (base class) for polymorphism.
   Client uses dynamic_cast to get concrete type if needed.
   Allows treating all clones the same way.

Q8: Memory management in Prototype?
A: clone() allocates with new.
   Client must delete all cloned objects.
   Consider using smart pointers (unique_ptr) for automatic cleanup.

Q9: How to implement deep copy?
A: In copy constructor:
   if (other.ptrData != nullptr) {
       ptrData = new Data(*other.ptrData);  // Allocate new memory
   }
   This creates independent copy.

Q10: Real-world examples?
A: 1. Game entities (clone base enemy, customize for level)
   2. Document templates (clone template, modify for new doc)
   3. Configuration objects (clone default config, modify for instance)
   4. UI components (clone button template, create variants)
   5. Database records (clone table schema, modify for new table)

================================================================================
REVISION CHECKLIST
================================================================================

□ Understand what Prototype pattern is
□ Know why it's useful (expensive vs cheap creation)
□ Understand copy constructor role
□ Know difference between shallow and deep copy
□ Understand polymorphic cloning
□ Know when to use Prototype
□ Can implement shallow copy clone
□ Can implement deep copy clone
□ Understand clone() returning base class pointer
□ Know memory management (new/delete)
□ Can answer all interview questions
□ Understand Prototype vs Factory comparison

================================================================================
*/
