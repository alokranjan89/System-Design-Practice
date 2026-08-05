#include <iostream>
using namespace std;

// ==========================================================
// SOLID Principle #4
// Interface Segregation Principle (ISP)
// ==========================================================

// Definition:
// A class should not be forced to implement
// methods that it does not use.
//
// Instead of one large interface,
// create multiple small, specific interfaces.

// ==========================================================
// Simple Meaning
// ==========================================================

// Don't force classes to implement
// unnecessary methods.
//
// One Interface = One Responsibility

// ==========================================================
// Why ISP?
// ==========================================================

// Large interfaces force classes to
// implement methods they don't need.
//
// This leads to:
//
// ❌ Empty methods
// ❌ Dummy implementations
// ❌ Confusing code
// ❌ Poor design

// ==========================================================
// BAD DESIGN
// ==========================================================

//                Worker
//
// ------------------------------------------------
//
// cook()
//
// serve()
//
// takePayment()
//
// Every employee is forced to implement
// every method.
//
// Chef ❌ takePayment()
//
// Cashier ❌ cook()
//
// Waiter ❌ cook()
//
// Violates ISP.

// ==========================================================
// GOOD DESIGN
// ==========================================================

//            Cook Interface
//
//            Serve Interface
//
//           Payment Interface
//
// Chef implements only Cook.
//
// Waiter implements only Serve.
//
// Cashier implements only Payment.
//
// No unnecessary methods.

// ==========================================================
// C++ Example
// ==========================================================

// ----------------------------------------------------------
// Cook Interface
// ----------------------------------------------------------

class Cook
{
public:

    virtual void cook() = 0;

    virtual ~Cook() {}
};

// ----------------------------------------------------------
// Serve Interface
// ----------------------------------------------------------

class Serve
{
public:

    virtual void serve() = 0;

    virtual ~Serve() {}
};

// ----------------------------------------------------------
// Payment Interface
// ----------------------------------------------------------

class Payment
{
public:

    virtual void takePayment() = 0;

    virtual ~Payment() {}
};

// ----------------------------------------------------------
// Chef
// ----------------------------------------------------------

class Chef : public Cook
{
public:

    void cook() override
    {
        cout << "Chef is cooking." << endl;
    }
};

// ----------------------------------------------------------
// Waiter
// ----------------------------------------------------------

class Waiter : public Serve
{
public:

    void serve() override
    {
        cout << "Waiter is serving food." << endl;
    }
};

// ----------------------------------------------------------
// Cashier
// ----------------------------------------------------------

class Cashier : public Payment
{
public:

    void takePayment() override
    {
        cout << "Cashier is taking payment." << endl;
    }
};

// ==========================================================
// Main
// ==========================================================

int main()
{
    Chef chef;
    Waiter waiter;
    Cashier cashier;

    chef.cook();

    waiter.serve();

    cashier.takePayment();

    return 0;
}

/*
================ OUTPUT ==================

Chef is cooking.
Waiter is serving food.
Cashier is taking payment.

==========================================
*/


// ==========================================================
// Code Explanation
// ==========================================================

// Cook
//
// Interface.
//
// Every cooking class implements cook().

// ----------------------------------------------------------

// Serve
//
// Interface.
//
// Every serving class implements serve().

// ----------------------------------------------------------

// Payment
//
// Interface.
//
// Every payment class implements takePayment().

// ----------------------------------------------------------

// Chef
//
// Implements only Cook.
//
// Not forced to implement:
//
// serve()
//
// takePayment()

// ----------------------------------------------------------

// Waiter
//
// Implements only Serve.
//
// Not forced to implement:
//
// cook()
//
// takePayment()

// ----------------------------------------------------------

// Cashier
//
// Implements only Payment.
//
// Not forced to implement:
//
// cook()
//
// serve()

// ==========================================================
// Where is ISP Used?
// ==========================================================

// ✔ Printer
//
// Printable
//
// Scannable
//
// Faxable

// ----------------------------------------------------------

// ✔ Notification
//
// EmailNotifier
//
// SMSNotifier
//
// PushNotifier

// ----------------------------------------------------------

// ✔ Payment Gateway
//
// Payable
//
// Refundable
//
// Verifiable

// ----------------------------------------------------------

// ✔ Authentication
//
// Login
//
// Logout
//
// PasswordReset

// ----------------------------------------------------------

// ✔ Cloud Storage
//
// Readable
//
// Writable
//
// Shareable

// ==========================================================
// How to Identify ISP Violation?
// ==========================================================

// Ask:
//
// "Is this class implementing
// methods it never uses?"
//
// YES → ISP Violation.

// ==========================================================
// Interview Keywords
// ==========================================================

// Client Specific Interface
//
// Small Interfaces
//
// Interface Splitting
//
// Loose Coupling
//
// No Unused Methods

// ==========================================================
// Common Mistakes
// ==========================================================

// ❌ One Giant Interface
//
// class Machine
// {
//      print();
//
//      scan();
//
//      fax();
// };
//
// SimplePrinter is forced to
// implement scan() and fax().
//
// Violates ISP.

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
//
// What is ISP?
//
// A class should not be forced
// to implement methods it
// doesn't need.

// ----------------------------------------------------------

// Q2.
//
// How do you achieve ISP?
//
// By splitting large interfaces
// into smaller interfaces.

// ----------------------------------------------------------

// Q3.
//
// Difference between SRP and ISP?
//
// SRP
//
// One Class
//
// One Responsibility.
//
// ISP
//
// One Interface
//
// One Responsibility.

// ----------------------------------------------------------

// Q4.
//
// Give a real-world example.
//
// Printer
//
// Restaurant
//
// Payment Gateway
//
// Notification System

// ==========================================================
// Interview Answer
// ==========================================================

// "Interface Segregation Principle states
// that a class should not be forced to
// implement methods it doesn't need.
//
// Instead of creating one large interface,
// we split it into multiple smaller,
// client-specific interfaces."

// ==========================================================
// Memory Trick
// ==========================================================

// SRP
//
// One Class
//
// One Responsibility.

// OCP
//
// Add New Class
//
// Don't Modify Existing Class.

// LSP
//
// Child should behave like Parent.

// ISP
//
// Small Interfaces.
//
// Don't force unnecessary methods.