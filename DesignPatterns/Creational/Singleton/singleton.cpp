/*
================================================================================
SINGLETON PATTERN - DETAILED REVISION NOTES
================================================================================

DEFINITION:
- Singleton is a Creational Design Pattern that restricts a class to have only
  ONE instance (object) throughout the application's lifetime.
- Provides global access to that single instance through a static method.
- Also called "Mono State" or "Single Instance" pattern.

WHY USE SINGLETON:
✓ Some resources should have only ONE instance (database connection, logger)
✓ Centralized access point for shared resources
✓ Controls instantiation (prevents multiple instances)
✓ Reduces memory usage (only one object created)
✓ Thread-safe resource management

WHEN TO USE:
✓ Database connections (one connection pool)
✓ Logging frameworks (one logger for entire application)
✓ Configuration managers (one config for whole app)
✓ Thread pools (one pool manages all threads)
✓ Caches (one cache shared globally)

WHEN NOT TO USE:
✗ Multiple instances are needed (violates Single Instance principle)
✗ Testing (hard to mock single instance)
✗ Stateful objects (each user needs own instance)
✗ Concurrent access issues (not thread-safe without synchronization)

SINGLETON APPROACHES:
┌──────────────────────────────────────────────────────────────────────────┐
│ APPROACH             │ WHEN CREATED  │ THREAD-SAFE? │ LAZY LOADING?     │
├──────────────────────┼───────────────┼──────────────┼───────────────────┤
│ Eager Initialization │ Before main() │ Yes (static) │ No (always created)│
│ Lazy Initialization  │ On first use  │ No (needs    │ Yes (created when  │
│                      │               │ mutex)       │ needed)            │
│ Double-Checked Lock  │ On first use  │ Yes (if done │ Yes                │
│                      │               │ correctly)   │                    │
│ Meyers Singleton     │ On first use  │ Yes (C++11+) │ Yes                │
│ (Static Local)       │               │              │                    │
└──────────────────────┴───────────────┴──────────────┴───────────────────┘

================================================================================
*/

#include <iostream>

using namespace std;

// ==========================
// SINGLETON CLASS - Eager Initialization
// ==========================
// PURPOSE: Ensure only ONE instance exists, accessible globally
// METHOD: Create instance before main() starts (eager initialization)
//
// IMPLEMENTATION STEPS:
// 1. Static pointer to hold the single instance
// 2. Private constructor (prevent direct instantiation)
// 3. getInstance() returns the static instance
// 4. Private copy constructor & assignment operator (prevent copying)

// Singleton using eager initialization with a static pointer.
//
// APPROACH: EAGER INITIALIZATION
// - Object created before main() starts
// - getInstance() simply returns existing object
// - Thread-safe by default (static initialization is thread-safe)
// - Always uses memory (even if never used)
//
// Steps:
// 1. Keep a static pointer named instance.
// 2. Create the Singleton object before main() starts.
// 3. Make the constructor private so outside code cannot create another object.
// 4. getInstance() only returns the already-created object.
// 5. Every call receives the same object address.
//
// Advantages:
// - Simple getInstance() logic.
// - No mutex is needed because the object is created before use.
// - Same instance is available immediately.
//
// Disadvantages:
// - Object is created even if the program never uses it.
// - Uses new, so object cleanup needs care.
// - Startup can become heavier if the object is expensive to create.

class Singleton
{
private:
   // Static pointer stores the only object of this class.
   // This is created once before main() runs
   static Singleton *instance;

   // Private constructor prevents creating objects directly in main().
   // Only getInstance() can create the instance (indirectly via static initialization)
   Singleton()
   {
      cout << "Singleton Constructor Called" << endl;
   }

   // Delete copy constructor to prevent copying
   Singleton(const Singleton &) = delete;

   // Delete assignment operator to prevent copying
   Singleton &operator=(const Singleton &) = delete;

public:
   // Static method to get the single instance
   // GUARANTEE: Always returns same object address
   // THREAD-SAFE: By static initialization (before main)
   static Singleton *getInstance()
   {
      // Return the object that was already created below.
      return instance;
   }

   // Add any application logic here
   void someMethod()
   {
      cout << "Doing something with singleton...\n";
   }
};

// ==========================
// STATIC INITIALIZATION - Creates instance before main()
// ==========================
// This line executes BEFORE main() is called
// Object is allocated once and never deallocated
// All getInstance() calls return this same instance
//
// MEMORY: Singleton object persists for entire program lifetime
// INITIALIZATION: Happens once during static initialization phase
Singleton *Singleton::instance = new Singleton();

int main()
{
   // ==========================
   // CLIENT CODE - SINGLETON USAGE
   // ==========================

   // Get singleton instance (first time)
   Singleton *s1 = Singleton::getInstance();
   cout << "s1 address: " << s1 << "\n";

   // Get singleton instance (second time)
   // Same instance returned, not a new one!
   Singleton *s2 = Singleton::getInstance();
   cout << "s2 address: " << s2 << "\n";

   // Comparison: Both pointers point to same object
   // Output: 1 (true) because s1 == s2
   cout << "\nAre s1 and s2 the same? " << (s1 == s2) << endl;

   // Use the singleton
   s1->someMethod();
   s2->someMethod();

   // Both s1 and s2 are the SAME object
   // Modifying through s1 affects s2

   return 0;
}

/*
================================================================================
REVISION Q&A - COMMON INTERVIEW QUESTIONS
================================================================================

Q1: What is Singleton Pattern?
A: Pattern that restricts a class to have only ONE instance throughout the
   application's lifetime. Provides global access via static getInstance().

Q2: Why make constructor private?
A: To prevent external code from creating new instances.
   Only getInstance() can create instance (indirectly).
   Ensures only one instance exists.

Q3: Eager vs Lazy initialization?
A: EAGER: Instance created before main() via static initialization.
          Always exists, thread-safe, uses memory even if unused.
   LAZY: Instance created on first getInstance() call.
         Saves memory, but needs mutex for thread-safety.

Q4: Is Singleton thread-safe?
A: Eager: YES (static initialization is thread-safe by language spec)
   Lazy: NO (without mutex; multiple threads could create instances)
   Meyers: YES (C++11 static local initialization is thread-safe)

Q5: Why delete copy constructor?
A: To prevent creating additional instances by copying.
   Singleton(const Singleton&) = delete; forces compile error on copy.

Q6: How to implement lazy Singleton?
A: static Singleton* getInstance() {
       if (instance == nullptr) {
           instance = new Singleton();
       }
       return instance;
   }
   PROBLEM: Not thread-safe! Use mutex for thread-safety.

Q7: What's Meyers Singleton (C++11)?
A: static Singleton& getInstance() {
       static Singleton instance;  // Created on first call, thread-safe
       return instance;
   }
   BEST APPROACH: Lazy, thread-safe, no mutex needed, no new/delete.

Q8: Can you create multiple instances?
A: No. Private constructor prevents direct instantiation.
   Deleted copy constructor prevents copying.
   No way to create second instance.

Q9: What about memory cleanup?
A: Singleton allocated with new persists until program ends.
   Not automatically freed (considered acceptable for singletons).
   Alternative: Meyers Singleton uses stack allocation (auto cleanup).

Q10: Real-world examples?
A: 1. Database connection pool (one connection manager)
   2. Logger framework (one logger instance)
   3. Application configuration (one config object)
   4. Thread pool (one pool manages all threads)
   5. File system (one file manager for entire app)
   6. Cache system (one cache shared globally)
   7. Print spooler (one queue for all print jobs)

Q11: Problems with Singleton?
A: 1. TESTING: Hard to mock single instance
   2. HIDDEN DEPENDENCY: Global state not obvious in method signature
   3. THREAD SAFETY: Not inherently thread-safe (depends on implementation)
   4. LIFETIME: Instance persists entire program lifetime (cleanup issues)
   5. COUPLING: Code depends on global state (tight coupling)

Q12: When NOT to use Singleton?
A: ✗ When multiple instances are needed
   ✗ In test code (hard to mock or reset)
   ✗ For stateful objects needing isolation
   ✗ In concurrent systems without proper synchronization
   ✗ When dependency injection would work better

Q13: Singleton vs Static Class?
A: SINGLETON:
   - Class with one instance
   - Can implement interfaces
   - Can be passed as object
   - Can have mutable state

   STATIC CLASS:
   - All methods are static
   - Can't instantiate
   - Can't implement interfaces
   - Only static data

Q14: How to reset Singleton in testing?
A: 1. Make getInstance() public in test-only mode
   2. Add resetInstance() method for testing
   3. Use dependency injection instead of Singleton
   4. Mock the Singleton in tests

   Example (for testing):
   static void resetInstance() {
       if (instance != nullptr) delete instance;
       instance = nullptr;
   }

Q15: Singleton Pattern Problems and Solutions?
A: PROBLEM: Multiple threads create instance (lazy + no mutex)
   SOLUTION: Use mutex or Meyers Singleton

   PROBLEM: Can't create multiple instances for different scenarios
   SOLUTION: Registry pattern + factory methods

   PROBLEM: Hard to test (global state)
   SOLUTION: Dependency injection

   PROBLEM: Memory not freed
   SOLUTION: Use Meyers Singleton (stack allocation) or cleanup method

================================================================================
SINGLETON IMPLEMENTATIONS COMPARISON
================================================================================

1. EAGER INITIALIZATION (This Example)
   ├─ Created: Before main()
   ├─ Thread-Safe: Yes (static init)
   ├─ Lazy Load: No (always created)
   ├─ Complexity: Simple
   └─ Best for: Simple, guaranteed use

2. LAZY INITIALIZATION (Manual)
   ├─ Created: First getInstance() call
   ├─ Thread-Safe: No (needs mutex)
   ├─ Lazy Load: Yes
   ├─ Complexity: Moderate
   └─ Best for: Expensive objects, may not be used

3. DOUBLE-CHECKED LOCKING
   ├─ Created: First getInstance() call
   ├─ Thread-Safe: Yes (complex)
   ├─ Lazy Load: Yes
   ├─ Complexity: High
   └─ Best for: Performance-critical + lazy

4. MEYERS SINGLETON (C++11+) - RECOMMENDED
   ├─ Created: First getInstance() call
   ├─ Thread-Safe: Yes (language guarantee)
   ├─ Lazy Load: Yes
   ├─ Complexity: Simple
   └─ Best for: Modern C++, ideal choice

================================================================================
REVISION CHECKLIST
================================================================================

□ Understand what Singleton pattern is
□ Know why only one instance should exist
□ Understand why constructor is private
□ Know difference between eager and lazy
□ Understand thread-safety requirements
□ Can implement eager Singleton
□ Can implement Meyers Singleton
□ Know how to prevent copying
□ Know testing strategies for Singleton
□ Understand when NOT to use
□ Can answer all interview questions
□ Know pros and cons
□ Understand Singleton vs Static class

================================================================================
*/


