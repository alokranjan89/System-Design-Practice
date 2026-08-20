/*
================================================================================
BUILDER PATTERN - DETAILED REVISION NOTES
================================================================================

DEFINITION:
- Builder is a Creational Design Pattern that separates the construction of
  a complex object from its representation.
- Constructs objects step-by-step, allowing flexible configuration.
- Used when an object has many optional parameters or complex initialization.

WHY USE BUILDER:
✓ Objects with many optional parameters (telescoping constructor problem)
✓ Complex initialization logic
✓ Multiple ways to configure same object
✓ Readable, fluent interface for object creation
✓ Immutable objects after construction

PROBLEM SOLVED - Telescoping Constructor:
// WITHOUT BUILDER (Hard to use!)
Computer c1(cpu, ram, ssd, gpu, rgb, wifi);
Computer c2(cpu, ram, ssd);  // Forget which parameter is which?
Computer c3(cpu, ram, ssd, true, false, true);  // What do true/false mean?

// WITH BUILDER (Clear and readable!)
Computer c1 = ComputerBuilder()
    .setCPU("Intel i9")
    .setRAM(32)
    .setSSD(1000)
    .setGPU(true)
    .setRGB(true)
    .build();

KEY COMPONENTS:
1. Product: Object being built (Computer)
2. Builder: Constructs product step-by-step (ComputerBuilder)
3. Director: Optional - orchestrates building process

WHEN TO USE:
✓ Objects with many optional parameters (3+)
✓ Complex initialization logic
✓ Need readable, fluent interface
✓ Want immutable objects
✓ Multiple configuration combinations

WHEN NOT TO USE:
✗ Simple objects with few attributes (overkill)
✗ All parameters are required (use constructor)
✗ Initialization is simple (not worth extra code)
✗ Performance-critical (slight overhead)

FLUENT INTERFACE (Method Chaining):
- Each setter returns *this (reference to builder)
- Allows chaining: builder.setA().setB().setC()
- Creates readable, natural language-like code
- Improves readability compared to nested function calls

================================================================================
*/

#include <iostream>
using namespace std;

// ======================================================
// Product
// ======================================================

// Product: The object being built by the Builder.
// In this example, `Computer` is the product with optional features like CPU, RAM, SSD, GPU, RGB, and WiFi.
//
// KEY POINTS:
// - Has many optional attributes
// - Usually initialized as zero/false by default
// - Normally would have a huge constructor (telescoping problem)
// - Builder solves this by letting client set only needed attributes
class Computer
{
public:
    string cpu;
    int ram;
    int ssd;
    bool gpu;
    bool rgb;
    bool wifi;

    void display()
    {
        cout << "\nComputer Configuration\n";
        cout << "----------------------\n";
        cout << "CPU  : " << cpu << endl;
        cout << "RAM  : " << ram << " GB" << endl;
        cout << "SSD  : " << ssd << " GB" << endl;
        cout << "GPU  : " << (gpu ? "Yes" : "No") << endl;
        cout << "RGB  : " << (rgb ? "Yes" : "No") << endl;
        cout << "WiFi : " << (wifi ? "Yes" : "No") << endl;
    }
};

// ======================================================
// Builder
// ======================================================

// Builder: Constructs the product step by step.
// Each setter configures the internal `Computer` instance and returns the builder for chaining.
//
// KEY CONCEPTS:
// 1. ENCAPSULATION: Holds internal product being built
// 2. FLUENT INTERFACE: Each setter returns *this for method chaining
// 3. SEPARATION: Building logic separated from product
// 4. FLEXIBILITY: Client controls which parts to set
//
// USAGE PATTERN:
// ComputerBuilder builder;
// builder.setCPU("Intel i9");    // Returns ComputerBuilder&
//         .setRAM(32);            // Returns ComputerBuilder&
//         .setSSD(1000);          // Returns ComputerBuilder&
//         .build();               // Returns Computer
//
// ADVANTAGES:
// ✓ Readable: Clear what each property means
// ✓ Flexible: Set only needed properties
// ✓ Safe: Compiler checks property names
// ✓ Chainable: Multiple calls on single line
// ✓ Optional: Can set defaults and override
class ComputerBuilder
{
private:
    Computer computer;

public:

    ComputerBuilder& setCPU(string cpu)
    {
        computer.cpu = cpu;
        return *this;  // Return reference for chaining
    }

    ComputerBuilder& setRAM(int ram)
    {
        computer.ram = ram;
        return *this;  // Return reference for chaining
    }

    ComputerBuilder& setSSD(int ssd)
    {
        computer.ssd = ssd;
        return *this;  // Return reference for chaining
    }

    ComputerBuilder& setGPU(bool gpu)
    {
        computer.gpu = gpu;
        return *this;  // Return reference for chaining
    }

    ComputerBuilder& setRGB(bool rgb)
    {
        computer.rgb = rgb;
        return *this;  // Return reference for chaining
    }

    ComputerBuilder& setWiFi(bool wifi)
    {
        computer.wifi = wifi;
        return *this;  // Return reference for chaining
    }

    // BUILD METHOD - Returns the configured product
    // Called when all desired properties are set
    // Returns Computer (the final product)
    Computer build()
    {
        return computer;
    }
};

// ======================================================
// Important Notes
// ======================================================

// - The Builder pattern is useful when an object has many optional parameters.
// - The builder provides a fluent interface for readable configuration chaining.
// - `build()` returns the configured product after all options are set.
// - This example mutates an internal `Computer` instance before returning it.
// - For production usage, validate required values or consider an immutable product.

// KEY FEATURES OF THIS IMPLEMENTATION:
// 1. FLUENT INTERFACE: Each setter returns ComputerBuilder& for chaining
// 2. FLEXIBLE: Set only the properties you need
// 3. READABLE: Each property name is self-documenting
// 4. CHAINABLE: Multiple calls on one line
// 5. CONVENIENT: No need to remember constructor parameter order

// ======================================================
// Main
// ======================================================

int main()
{
    // ==========================
    // EXAMPLE 1: Gaming Computer
    // ==========================
    // 
    // Using Builder pattern instead of constructor:
    // Gaming PC with all features enabled
    // Shows fluent interface (method chaining)
    cout << "========================================\n";
    cout << "EXAMPLE 1: Building Gaming PC\n";
    cout << "========================================\n\n";
    
    Computer gamingPC = ComputerBuilder()
                            .setCPU("Intel i9")      // High-end CPU
                            .setRAM(32)              // Maximum RAM
                            .setSSD(1000)            // Large SSD
                            .setGPU(true)            // Need graphics
                            .setRGB(true)            // For aesthetics
                            .setWiFi(true)           // Always useful
                            .build();                // Finalize product

    gamingPC.display();

    // ==========================
    // EXAMPLE 2: Office Computer
    // ==========================
    // 
    // Building office PC with minimal features
    // Shows flexibility: only set what's needed
    cout << "\n========================================\n";
    cout << "EXAMPLE 2: Building Office PC\n";
    cout << "========================================\n\n";
    
    Computer officePC = ComputerBuilder()
                            .setCPU("Intel i5")      // Budget CPU
                            .setRAM(16)              // Moderate RAM
                            .setSSD(512)             // Small SSD
                            .setGPU(false)           // No GPU needed
                            .setRGB(false)           // No RGB
                            .setWiFi(true)           // WiFi needed
                            .build();                // Finalize product

    officePC.display();

    return 0;
}

/*
================================================================================
REVISION Q&A - COMMON INTERVIEW QUESTIONS
================================================================================

Q1: What is Builder Pattern?
A: Pattern that separates object construction from representation, allowing
   step-by-step building of complex objects. Solves telescoping constructor.

Q2: Telescoping Constructor Problem?
A: When object has many optional parameters:
   Computer(cpu);
   Computer(cpu, ram);
   Computer(cpu, ram, ssd);
   Computer(cpu, ram, ssd, gpu);
   // 10 parameters = 10 different constructors!
   // Confusing which parameter is which
   // Builder solves by using named setters

Q3: What is Fluent Interface?
A: Each method returns *this (reference to builder) for method chaining.
   builder.setA().setB().setC().build();
   Instead of:
   builder.setA();
   builder.setB();
   builder.setC();
   builder.build();

Q4: When should you use Builder?
A: ✓ Objects with 3+ optional parameters
   ✓ Complex initialization logic
   ✓ Multiple configuration combinations
   ✓ Need readable code
   ✓ Want immutable products

Q5: Builder vs Constructor?
A: CONSTRUCTOR: Simple, direct, all at once
   BUILDER: Flexible, readable, step-by-step
   
   Use constructor for 1-2 parameters.
   Use builder for 3+ optional parameters.

Q6: Can Builder guarantee valid objects?
A: Yes! Add validation in build():
   Computer build() {
       if (cpu.empty()) throw Exception("CPU required!");
       return computer;
   }

Q7: What about immutability?
A: Once build() returns Computer, can't modify it.
   Make Computer members private, no setters.
   This implementation returns by value (copy).

Q8: Builder vs Factory Method?
A: FACTORY: Which object to create
   BUILDER: How to build single object
   
   Use Factory when types vary.
   Use Builder when configuration varies.

Q9: Director pattern - what is it?
A: Optional component that orchestrates building:
   Director {
       Computer buildGamingPC(Builder& b) {
           return b.setCPU("i9").setGPU(true).build();
       }
   }
   Encapsulates complex building strategies.

Q10: Real-world examples?
A: 1. SQL query builder (SELECT... WHERE... ORDER BY...)
   2. StringBuilder in Java (.append().append().toString())
   3. HTTP request builder (.setURL().setMethod().setHeaders().send())
   4. Configuration objects (with many options)
   5. HTML/XML builders (.addElement().addAttribute())
   6. Database connection string builders
   7. Protobuf message builders

Q11: Performance considerations?
A: Slight overhead:
   ✓ Extra object allocation (builder)
   ✓ Extra method calls (setters)
   But generally negligible for most applications.
   Tradeoff: Readability vs performance (worth it!)

Q12: How to handle required parameters?
A: 1. Constructor with required params:
      ComputerBuilder(string cpu) { this->cpu = cpu; }
   
   2. Validation in build():
      if (cpu.empty()) throw Exception("CPU required!");
   
   3. Separate builder factory:
      Builder& withCPU(string cpu);

Q13: Nested vs Separate Builder?
A: NESTED (Inner class):
   class Computer {
       class Builder { }
   }
   Advantage: Cleaner namespace
   
   SEPARATE:
   class Computer { }
   class ComputerBuilder { }
   Advantage: Simpler, can reuse for different products

Q14: Builder with inheritance?
A: Complex but possible:
   - Make builder generic/template
   - Use CRTP (Curiously Recurring Template Pattern)
   - Return derived builder type from setters

Q15: Testing with Builder?
A: VERY easy to test!
   // Test default values
   Computer c1 = ComputerBuilder().build();
   
   // Test specific combinations
   Computer c2 = ComputerBuilder()
       .setCPU("Custom").build();
   
   // Much better than trying constructor overloads

================================================================================
COMPARISON WITH OTHER PATTERNS
================================================================================

BUILDER vs ABSTRACT FACTORY:
- Builder: How to build ONE object
- Factory: Which object to create
- Builder: Step-by-step configuration
- Factory: One-step object creation
- Use Builder for complex single object
- Use Factory for multiple object types

BUILDER vs PROTOTYPE:
- Builder: Construct from scratch with steps
- Prototype: Copy existing object
- Builder: For flexible configuration
- Prototype: For expensive cloning
- Use Builder for custom creation
- Use Prototype for template copying

================================================================================
REVISION CHECKLIST
================================================================================

□ Understand what Builder pattern is
□ Know telescoping constructor problem
□ Understand fluent interface (method chaining)
□ Know when to use Builder
□ Can implement fluent interface (return *this)
□ Can implement build() method
□ Know how to add validation
□ Know difference with Factory and Prototype
□ Understand immutability with Builder
□ Know real-world examples
□ Can design builder for complex objects
□ Can answer all interview questions
□ Know nested vs separate builder

================================================================================
KEY TAKEAWAYS

1. **Solves Telescoping Constructor Problem** - Too many overloads
2. **Fluent Interface** - Return *this for method chaining
3. **Flexible Configuration** - Set only needed properties
4. **Readable Code** - Self-documenting property names
5. **Step-by-Step Building** - Build complex objects gradually
6. **Optional Parameters** - Handle many optional attributes
7. **Separation of Concerns** - Building logic separate from product
8. **Real-world Useful** - SQL, HTTP, HTML builders everywhere

================================================================================
*/