#include <iostream>
using namespace std;

// ==========================================================
// SOLID Principle #2
// Open Closed Principle (OCP)
// ==========================================================

// Definition:
// Software entities (Classes, Functions, Modules)
// should be OPEN for Extension
// but CLOSED for Modification.

// Meaning:
// Don't modify existing code.
// Extend it by creating new classes.

// ==========================================================
// BAD DESIGN
// ==========================================================

// class Payment
// {
// public:
//
//     void pay(string method)
//     {
//         if(method=="UPI")
//         {
//              ...
//         }
//         else if(method=="Card")
//         {
//              ...
//         }
//         else if(method=="PayPal")
//         {
//              ...
//         }
//     }
// }
//
// Tomorrow Bitcoin comes.
//
// Modify pay() again.
//
// Violates OCP.

// ==========================================================
// GOOD DESIGN
// ==========================================================

//                     Payment
//                        |
//        --------------------------------
//        |               |             |
//      UPI         CreditCard      PayPal
//
// Tomorrow:
//
// Bitcoin
//
// Simply create
//
// class Bitcoin : public Payment
//
// No old code changes.

// ==========================================================
// STEP 1
// Create Abstract Base Class
// ==========================================================

class Payment
{
public:

    // Pure Virtual Function
    // Every child class MUST implement pay()

    virtual void pay() = 0;

    // Virtual Destructor

    virtual ~Payment() {}
};

// ==========================================================
// STEP 2
// Credit Card Payment
// ==========================================================

class CreditCard : public Payment
{
public:

    void pay() override
    {
        cout << "Paid using Credit Card" << endl;
    }
};

// ==========================================================
// STEP 3
// UPI Payment
// ==========================================================

class UPI : public Payment
{
public:

    void pay() override
    {
        cout << "Paid using UPI" << endl;
    }
};

// ==========================================================
// STEP 4
// PayPal Payment
// ==========================================================

class PayPal : public Payment
{
public:

    void pay() override
    {
        cout << "Paid using PayPal" << endl;
    }
};

// ==========================================================
// STEP 5
// Main Function
// ==========================================================

int main()
{
    // Base class pointer

    Payment* payment;

    // Credit Card

    CreditCard card;

    payment = &card;

    payment->pay();

    // UPI

    UPI upi;

    payment = &upi;

    payment->pay();

    // PayPal

    PayPal paypal;

    payment = &paypal;

    payment->pay();

    return 0;
}

/*
======================== OUTPUT ========================

Paid using Credit Card
Paid using UPI
Paid using PayPal

========================================================
*/


// ==========================================================
// CODE EXPLANATION
// ==========================================================

// class Payment
//
// Abstract Base Class.
//
// It provides a common interface.
//
// Every payment method must implement pay().

// ----------------------------------------------------------

// virtual void pay() = 0;
//
// Pure Virtual Function.
//
// Makes Payment an Abstract Class.
//
// Cannot create:
//
// Payment p;   ❌
//
// Child classes MUST override pay().

// ----------------------------------------------------------

// virtual ~Payment(){}
//
// Virtual Destructor.
//
// Ensures correct cleanup when deleting
// objects through a base class pointer.

// ----------------------------------------------------------

// class CreditCard : public Payment
//
// Inherits from Payment.
//
// Implements its own version of pay().

// ----------------------------------------------------------

// override
//
// Tells the compiler:
//
// "I am overriding the parent class function."
//
// Compiler gives an error if the signature is wrong.

// ----------------------------------------------------------

// Payment* payment;
//
// Base class pointer.
//
// Can point to ANY child object.
//
// Example:
//
// payment = &card;
//
// payment = &upi;
//
// payment = &paypal;
//
// This is Runtime Polymorphism.

// ----------------------------------------------------------

// payment->pay();
//
// Calls the correct function depending on
// which object payment points to.
//
// Card -> CreditCard::pay()
//
// UPI -> UPI::pay()
//
// PayPal -> PayPal::pay()

// ==========================================================
// HOW DOES THIS FOLLOW OCP?
// ==========================================================

// Tomorrow interviewer says:
//
// Add Bitcoin Payment.
//
// We simply write:
//
// class Bitcoin : public Payment
// {
// public:
//
//     void pay() override
//     {
//         cout<<"Paid using Bitcoin";
//     }
// };
//
// That's it.
//
// Existing classes remain unchanged.
//
// OCP achieved.

// ==========================================================
// WHERE IS OCP USED?
// ==========================================================

// ✔ Payment Gateway
// ✔ Notification System
// ✔ Authentication
// ✔ Tax Calculation
// ✔ Discount System
// ✔ Vehicle Types
// ✔ File Export
// ✔ Shipping Partner

// ==========================================================
// INTERVIEW QUESTIONS
// ==========================================================

// Q1.
//
// What is OCP?
//
// Open for Extension
//
// Closed for Modification.

// ----------------------------------------------------------

// Q2.
//
// How do you implement OCP?
//
// Abstract Class
//
// Inheritance
//
// Virtual Function
//
// Runtime Polymorphism

// ----------------------------------------------------------

// Q3.
//
// Why avoid modifying old code?
//
// Old code is already tested.
//
// Modifying it can introduce bugs.

// ----------------------------------------------------------

// Q4.
//
// What happens if tomorrow Bitcoin payment is added?
//
// Create:
//
// class Bitcoin : public Payment
//
// No existing code changes.

// ==========================================================
// INTERVIEW KEYWORDS
// ==========================================================

// Open for Extension
//
// Closed for Modification
//
// Interface
//
// Abstract Class
//
// Runtime Polymorphism
//
// Extensible Design
//
// Inheritance
//
// Dynamic Binding