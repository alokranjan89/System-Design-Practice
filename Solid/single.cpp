// ==========================================
// SOLID PRINCIPLE #1
// Single Responsibility Principle (SRP)
// ==========================================

// Definition:
// A class should have only ONE responsibility
// or ONE reason to change.

// Simple Meaning:
// One class = One Job

// Bad Example:
//
// class Order
// {
//     createOrder();
//     calculateTax();
//     saveToDatabase();
//     sendInvoice();
// }
//
// Why is this bad?
// - Handles Order Logic
// - Handles Tax Logic
// - Handles Database Logic
// - Handles Email Logic
//
// If tax rules change -> modify Order
// If database changes -> modify Order
// If email service changes -> modify Order
//
// Multiple reasons to change -> Violates SRP

// ------------------------------------------

// Good Design
//
// Order
//   |
//   |--> OrderRepository   -> Database
//   |
//   |--> TaxService        -> Tax Calculation
//   |
//   |--> EmailService      -> Send Emails
//
// Every class has ONE responsibility.

// ==========================================
// Why SRP?
// ==========================================

// 1. Easy to Maintain
// 2. Easy to Test
// 3. Easy to Debug
// 4. Less Coupling
// 5. High Cohesion
// 6. Better Code Reusability

// ==========================================
// Interview Definition
// ==========================================

// "A class should have only one reason to change.
// Each class should focus on one responsibility."

// ==========================================
// Real World Example
// ==========================================

// Restaurant
//
// Chef        -> Cook Food
// Waiter      -> Serve Food
// Cashier     -> Take Payment
//
// Everyone has ONE responsibility.
//
// Same idea in software.

// ==========================================
// Interview Question
// ==========================================

// Q. Does one responsibility mean one method?
//
// No.
//
// A class can have many methods as long as they
// all belong to the SAME responsibility.

// Example:
//
// class EmailService
// {
//     validateEmail();
//     connectSMTP();
//     sendEmail();
// }
//
// All methods belong to Email Service.

// ==========================================
// Interview Keywords
// ==========================================

// Responsibility
// Reason to Change
// Maintainability
// High Cohesion
// Low Coupling
// Separation of Concerns (SoC)

// ==========================================
// Interview Answer in One Line
// ==========================================

// "Single Responsibility Principle states that
// a class should have only one responsibility
// and therefore only one reason to change."

// ==========================================
// Example Classes
// ==========================================

// Order               -> Stores Order Data
// OrderRepository     -> Database Operations
// TaxService          -> Tax Calculation
// EmailService        -> Email Notifications

// ==========================================
// Common Mistake
// ==========================================

// SRP DOES NOT mean:
//
// One class = One method ❌
//
// SRP means:
//
// One class = One responsibility ✅


// ======================================================
// C++ Example
// ======================================================

#include <iostream>
using namespace std;

// ------------------------------------------------------
// Order Class
// Responsibility:
// Only stores order information.
// ------------------------------------------------------

class Order
{
private:
    int orderId;

public:

    // Constructor
    // Called automatically when an object is created.
    Order(int id)
    {
        this->orderId = id;
    }

    // Getter Function
    // Returns the order ID.
    int getOrderId()
    {
        return orderId;
    }
};

// ------------------------------------------------------
// OrderRepository
// Responsibility:
// Handles only database operations.
// ------------------------------------------------------

class OrderRepository
{
public:

    void save(Order &order)
    {
        cout << "Saving Order "
             << order.getOrderId()
             << " to Database." << endl;
    }
};

// ------------------------------------------------------
// TaxService
// Responsibility:
// Calculates tax only.
// ------------------------------------------------------

class TaxService
{
public:

    double calculateTax(double amount)
    {
        return amount * 0.18;
    }
};

// ------------------------------------------------------
// EmailService
// Responsibility:
// Sends invoice emails.
// ------------------------------------------------------

class EmailService
{
public:

    void sendInvoice(Order &order)
    {
        cout << "Invoice sent for Order "
             << order.getOrderId()
             << endl;
    }
};

// ======================================================
// Main Function
// ======================================================

int main()
{
    // Create an Order object.
    Order order(101);

    // Create service objects.
    OrderRepository repository;
    TaxService taxService;
    EmailService emailService;

    // Calculate tax.
    double tax = taxService.calculateTax(1000);

    cout << "Tax = " << tax << endl;

    // Save order to database.
    repository.save(order);

    // Send invoice email.
    emailService.sendInvoice(order);

    return 0;
}

/*
======================== OUTPUT ========================

Tax = 180
Saving Order 101 to Database.
Invoice sent for Order 101

========================================================
*/


// ======================================================
// Code Explanation
// ======================================================

// class Order
// ----------------
// Represents the Order entity.
// Stores only order-related information.
//
// Follows SRP because it only stores data.

// private:
// ----------------
// orderId cannot be accessed directly from outside.
// Data is protected through encapsulation.

// Constructor
// ----------------
// Order(int id)
//
// Runs automatically when an object is created.
//
// Example:
//
// Order order(101);
//
// Internally:
//
// this->orderId = id;

// this pointer
// ----------------
// 'this' points to the current object.
//
// this->orderId = id;
//
// means:
//
// Current object's orderId = constructor parameter id

// Getter
// ----------------
// getOrderId()
//
// Returns the private orderId.
//
// Used because private members cannot be accessed directly.

// ------------------------------------------------------

// OrderRepository
//
// Responsibility:
// Database operations only.
//
// If database changes,
// only this class changes.

// ------------------------------------------------------

// TaxService
//
// Responsibility:
// Tax calculation.
//
// If GST changes from 18% to 20%,
// only TaxService changes.

// ------------------------------------------------------

// EmailService
//
// Responsibility:
// Sending invoice emails.
//
// If SMTP or email provider changes,
// only EmailService changes.

// ------------------------------------------------------

// main()
//
// Creates objects.
//
// Calls services.
//
// Does not contain business logic.
//
// Acts as a coordinator between classes.

// ======================================================
// Interview Flow
// ======================================================

// Interviewer:
// Why is this SRP?
//
// Answer:
// Because every class has exactly one responsibility.
//
// Order -> Order data
// TaxService -> Tax calculation
// OrderRepository -> Database
// EmailService -> Email

// If any one responsibility changes,
// only one class needs modification.

// This makes the code:
// ✔ Easy to maintain
// ✔ Easy to test
// ✔ Easy to extend
// ✔ Less coupled
// ✔ Highly cohesive