#include <iostream>
using namespace std;

// ==========================================================
// SOLID Principle #3
// Liskov Substitution Principle (LSP)
// ==========================================================

// Definition:
// Objects of a child class should be replaceable
// with objects of the parent class without
// changing the correctness of the program.

// Simple Meaning:
//
// If Child IS-A Parent,
// then Child should behave like Parent.
//
// Parent* p = new Child();
//
// This should work correctly.

// ==========================================================
// Why LSP?
// ==========================================================

// If a child class changes the expected behavior
// of the parent class, inheritance is wrong.
//
// Child classes should never:
//
// ❌ Throw unexpected exceptions
// ❌ Remove parent functionality
// ❌ Change expected behavior

// ==========================================================
// Bad Example
// ==========================================================

//               Bird
//                 |
//        ----------------
//        |              |
//    Sparrow        Penguin
//
// Bird has:
//
// fly()
//
// Penguin cannot fly.
//
// Someone writes:
//
// Bird* bird = new Penguin();
//
// bird->fly();
//
// Program breaks.
//
// LSP Violated.

// ==========================================================
// Good Design
// ==========================================================

//                  Bird
//                    |
//          ------------------
//          |                |
//     FlyingBird        Penguin
//          |
//     ----------------
//     |              |
// Sparrow        Eagle
//
// Only FlyingBird has fly().
//
// Penguin isn't forced to fly.
//
// LSP Satisfied.

// ==========================================================
// C++ Example
// ==========================================================

// ----------------------------------------------------------
// Parent Class
// ----------------------------------------------------------

class Bird
{
public:

    virtual void eat()
    {
        cout << "Bird is eating." << endl;
    }

    virtual ~Bird() {}
};

// ----------------------------------------------------------
// FlyingBird
// ----------------------------------------------------------

class FlyingBird : public Bird
{
public:

    virtual void fly()
    {
        cout << "Bird is flying." << endl;
    }
};

// ----------------------------------------------------------
// Sparrow
// ----------------------------------------------------------

class Sparrow : public FlyingBird
{
public:

    void fly() override
    {
        cout << "Sparrow is flying." << endl;
    }
};

// ----------------------------------------------------------
// Eagle
// ----------------------------------------------------------

class Eagle : public FlyingBird
{
public:

    void fly() override
    {
        cout << "Eagle is flying." << endl;
    }
};

// ----------------------------------------------------------
// Penguin
// ----------------------------------------------------------

class Penguin : public Bird
{
public:

    // Penguins eat.
    // Penguins don't fly.
};

// ==========================================================
// Main Function
// ==========================================================

int main()
{
    Sparrow sparrow;
    Eagle eagle;
    Penguin penguin;

    sparrow.eat();
    sparrow.fly();

    eagle.eat();
    eagle.fly();

    penguin.eat();

    return 0;
}

/*
==================== OUTPUT ====================

Bird is eating.
Sparrow is flying.

Bird is eating.
Eagle is flying.

Bird is eating.

===============================================
*/

// ==========================================================
// Code Explanation
// ==========================================================

// Bird
//
// Parent class.
//
// Contains functionality common to every bird.
//
// Every bird can eat.

// ----------------------------------------------------------

// FlyingBird
//
// Inherits Bird.
//
// Adds flying capability.
//
// Only birds that can fly inherit this class.

// ----------------------------------------------------------

// Sparrow
//
// Overrides fly().
//
// Behaves correctly as a FlyingBird.

// ----------------------------------------------------------

// Eagle
//
// Overrides fly().
//
// Behaves correctly as a FlyingBird.

// ----------------------------------------------------------

// Penguin
//
// Inherits only Bird.
//
// Penguin can eat.
//
// Penguin doesn't inherit fly() because
// penguins cannot fly.
//
// This prevents incorrect behavior.

// ==========================================================
// Where is LSP Used?
// ==========================================================

// ✔ Payment Gateway
//
// Payment
// |
// |-- CreditCard
// |-- UPI
// |-- PayPal

// Every payment should support pay().

// ----------------------------------------------------------

// ✔ Vehicle System
//
// Vehicle
// |
// |-- Car
// |-- Bike
// |-- Truck

// Every vehicle should support:
//
// start()
// stop()

// ----------------------------------------------------------

// ✔ Notification System
//
// Notification
// |
// |-- Email
// |-- SMS
// |-- Push

// Every notification should send().

// ----------------------------------------------------------

// ✔ Authentication
//
// Login
// |
// |-- Google
// |-- GitHub
// |-- Facebook

// Every login should authenticate().

// ----------------------------------------------------------

// ✔ Shape
//
// Shape
// |
// |-- Circle
// |-- Rectangle
// |-- Triangle

// Every shape should draw().

// ==========================================================
// Interview Keywords
// ==========================================================

// ✔ IS-A Relationship
// ✔ Substitutability
// ✔ Runtime Polymorphism
// ✔ Correct Behavior
// ✔ Inheritance
// ✔ Parent-Child Relationship

// ==========================================================
// Common Mistakes
// ==========================================================

// ❌ Child removes functionality.
//
// ❌ Child throws unexpected exception.
//
// ❌ Child changes expected behavior.
//
// If Parent* points to Child,
// code should still work correctly.

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
// What is LSP?
//
// Child objects should replace parent
// objects without breaking the program.

// ----------------------------------------------------------

// Q2.
// What is the famous LSP example?
//
// Bird -> Penguin

// ----------------------------------------------------------

// Q3.
// Difference between OCP and LSP?
//
// OCP:
// Extend without modifying.
//
// LSP:
// Child should behave like Parent.

// ==========================================================
// Interview Answer
// ==========================================================

// "Liskov Substitution Principle states that
// objects of a child class should be usable
// wherever objects of the parent class are
// expected without changing the correctness
// of the program."