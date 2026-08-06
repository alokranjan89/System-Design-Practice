#include <iostream>
using namespace std;

// ==========================================================
// SOLID Principle #5
// Dependency Inversion Principle (DIP)
// ==========================================================

// Definition:
//
// High-level modules should not depend on
// low-level modules.
//
// Both should depend on abstractions.
//
// Abstractions should not depend on details.
//
// Details should depend on abstractions.

// ==========================================================
// Simple Meaning
// ==========================================================

// Don't directly depend on concrete classes.
//
// Depend on Interfaces (Abstractions).

// Instead of:
//
// OrderService
//        |
//        |
//     MySQLDatabase
//
// Use:
//
// OrderService
//        |
//        |
//     Database (Interface)
//        |
//   -----------------------
//   |                     |
// MySQL              PostgreSQL

// ==========================================================
// Why DIP?
// ==========================================================

// Suppose today:
//
// MySQL
//
// Tomorrow:
//
// PostgreSQL
//
// MongoDB
//
// Firebase
//
// We shouldn't modify OrderService.
//
// Just create another implementation.

// ==========================================================
// BAD DESIGN
// ==========================================================

// class MySQLDatabase
// {
// public:
//
//     void save()
//     {
//         cout<<"Saving to MySQL";
//     }
// };
//
// class OrderService
// {
//     MySQLDatabase db;
//
// public:
//
//     void placeOrder()
//     {
//          db.save();
//     }
// };
//
// Tomorrow:
//
// PostgreSQL
//
// Need to modify OrderService.
//
// Violates DIP.

// ==========================================================
// GOOD DESIGN
// ==========================================================

//                  Database
//
//                      ▲
//
//        --------------------------
//
//      MySQLDatabase
//
//      PostgreSQLDatabase
//
//      MongoDatabase
//
// OrderService depends on
// Database interface.

// ==========================================================
// Step 1
// Database Interface
// ==========================================================

class Database
{
public:

    virtual void save() = 0;

    virtual ~Database() {}
};

// ==========================================================
// Step 2
// MySQL
// ==========================================================

class MySQLDatabase : public Database
{
public:

    void save() override
    {
        cout << "Saving data in MySQL" << endl;
    }
};

// ==========================================================
// Step 3
// PostgreSQL
// ==========================================================

class PostgreSQLDatabase : public Database
{
public:

    void save() override
    {
        cout << "Saving data in PostgreSQL" << endl;
    }
};

// ==========================================================
// Step 4
// Order Service
// ==========================================================

class OrderService
{
private:

    Database* database;

public:

    OrderService(Database* db)
    {
        database = db;
    }

    void placeOrder()
    {
        cout << "Order Placed" << endl;

        database->save();
    }
};

// ==========================================================
// Main
// ==========================================================

int main()
{
    MySQLDatabase mysql;

    OrderService service(&mysql);

    service.placeOrder();

    cout << endl;

    PostgreSQLDatabase postgres;

    OrderService service2(&postgres);

    service2.placeOrder();

    return 0;
}

/*

================== OUTPUT ==================

Order Placed
Saving data in MySQL

Order Placed
Saving data in PostgreSQL

============================================

*/


// ==========================================================
// Code Explanation
// ==========================================================

// Database
//
// Abstract Interface.
//
// Every database must implement:
//
// save()

// ----------------------------------------------------------

// MySQLDatabase
//
// Concrete implementation.
//
// Saves into MySQL.

// ----------------------------------------------------------

// PostgreSQLDatabase
//
// Another implementation.
//
// Saves into PostgreSQL.

// ----------------------------------------------------------

// OrderService
//
// High Level Module.
//
// Doesn't know whether data
// is stored in:
//
// MySQL
//
// PostgreSQL
//
// MongoDB
//
// It only knows:
//
// Database Interface.

// ----------------------------------------------------------

// Constructor
//
// OrderService(Database* db)
//
// Dependency Injection.
//
// Database is provided from outside.
//
// OrderService does not create it.

// ----------------------------------------------------------

// database->save();
//
// Runtime Polymorphism.
//
// Correct save() executes
// depending on actual object.

// ==========================================================
// Where is DIP Used?
// ==========================================================

// ✔ Database Layer
//
// MySQL
//
// PostgreSQL
//
// MongoDB

// ----------------------------------------------------------

// ✔ Payment Gateway
//
// UPI
//
// Credit Card
//
// PayPal

// ----------------------------------------------------------

// ✔ Notification
//
// Email
//
// SMS
//
// Push Notification

// ----------------------------------------------------------

// ✔ Logger
//
// Console Logger
//
// File Logger
//
// Cloud Logger

// ----------------------------------------------------------

// ✔ Authentication
//
// Google
//
// GitHub
//
// Facebook

// ----------------------------------------------------------

// ✔ Storage
//
// AWS S3
//
// Azure Blob
//
// Google Cloud Storage

// ==========================================================
// How to Identify DIP Violation?
// ==========================================================

// High-level class creates
// concrete objects directly.
//
// Example:
//
// MySQLDatabase db;
//
// OrderService depends
// directly on MySQL.
//
// Violates DIP.

// ==========================================================
// Interview Keywords
// ==========================================================

// Dependency Injection
//
// Abstraction
//
// Interface
//
// Loose Coupling
//
// High-Level Module
//
// Low-Level Module
//
// Runtime Polymorphism

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
//
// What is DIP?
//
// High-level modules should not
// depend on low-level modules.
//
// Both should depend on abstractions.

// ----------------------------------------------------------

// Q2.
//
// How do you implement DIP?
//
// Interfaces
//
// Abstract Classes
//
// Dependency Injection

// ----------------------------------------------------------

// Q3.
//
// Why is Dependency Injection useful?
//
// Easy to replace implementations.
//
// Easy to test.
//
// Loose coupling.

// ----------------------------------------------------------

// Q4.
//
// Real-world Example?
//
// Database
//
// Logger
//
// Payment Gateway
//
// Notification System

// ==========================================================
// Interview Answer
// ==========================================================

// "Dependency Inversion Principle states that
// high-level modules should not depend on
// low-level modules. Both should depend on
// abstractions.
//
// For example, instead of OrderService
// directly depending on MySQLDatabase,
// it depends on a Database interface.
// This allows us to switch from MySQL
// to PostgreSQL without modifying
// OrderService."

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
// Add New Class.
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

// DIP
//
// Depend on Interfaces.
//
// Not Concrete Classes.

/**
 "Dependency Inversion Principle states that high-level modules should not depend directly on low-level modules. Instead, both should depend on abstractions such as interfaces or abstract classes. For example, instead of OrderService depending directly on MySQLDatabase, it should depend on a Database interface. This allows us to switch from MySQL to PostgreSQL or MongoDB without modifying the business logic. The result is loose coupling, easier testing, and better maintainability."

 "Business logic should never know implementation details."
 "Depend on Interfaces, not Implementations."
 */