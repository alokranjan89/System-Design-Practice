#include <iostream>
using namespace std;

// ==========================================================
// DRY Principle
// Don't Repeat Yourself
// ==========================================================

// Definition:
//
// Every piece of knowledge or business logic
// should exist in only ONE place in the codebase.
//
// If the same logic is repeated,
// create a reusable function/class/component.

// ==========================================================
// Simple Meaning
// ==========================================================

// Write Once.
//
// Reuse Everywhere.

// ==========================================================
// Why DRY?
// ==========================================================

// Duplicate code creates problems.
//
// If business logic changes,
// we must modify multiple places.
//
// This increases:
//
// BAD: Bugs
// BAD: Maintenance Cost
// BAD: Development Time

// DRY solves this by keeping
// logic in one place.

// ==========================================================
// BAD DESIGN
// ==========================================================

// Tax calculation repeated everywhere.

// double tax = amount * 0.18;
//
// ...
//
// double tax = amount * 0.18;
//
// ...
//
// double tax = amount * 0.18;
//
// Tomorrow GST changes.
//
// Must modify every location.
//
// Violates DRY.

// ==========================================================
// GOOD DESIGN
// ==========================================================

// Create one reusable function.
//
// calculateTax()
//
// Use it everywhere.

// ==========================================================
// C++ Example
// ==========================================================

// Tax calculation written only once.

double calculateTax(double amount)
{
    return amount * 0.18;
}

int main()
{
    double amount1 = 1000;
    double amount2 = 5000;
    double amount3 = 8000;

    cout << "Tax : " << calculateTax(amount1) << endl;

    cout << "Tax : " << calculateTax(amount2) << endl;

    cout << "Tax : " << calculateTax(amount3) << endl;

    return 0;
}

/*

================ OUTPUT =================

Tax : 180
Tax : 900
Tax : 1440

==========================================

*/


// ==========================================================
// Code Explanation
// ==========================================================

// calculateTax()
//
// Stores tax calculation logic.
//
// Instead of writing:
//
// amount * 0.18
//
// everywhere,
// we write it once.
//
// Every module reuses it.

// ----------------------------------------------------------

// main()
//
// Different amounts.
//
// Same function.
//
// No duplicate code.

// ==========================================================
// Another Example
// ==========================================================

// BAD

// if(user.role=="ADMIN")
//
// repeated in
//
// Dashboard
//
// Orders
//
// Products
//
// Users
//
// Settings

// Tomorrow
//
// ADMIN becomes SUPER_ADMIN.
//
// Modify 20 files.

// ----------------------------------------------------------

// GOOD

bool isAdmin(string role)
{
    return role == "ADMIN";
}

// Use

// if(isAdmin(user.role))

// Tomorrow change only
// one function.

// ==========================================================
// Real World Example
// ==========================================================

// College Exam Schedule
//
// BAD
//
// Every classroom keeps
// its own timetable.
//
// Change exam date.
//
// Update every classroom.

// ----------------------------------------------------------

// GOOD
//
// One Notice Board.
//
// Every classroom checks it.
//
// Update once.
//
// Everyone gets latest information.

// ==========================================================
// Where is DRY Used?
// ==========================================================

// OK: Tax Calculation
//
// OK: Discount Calculation
//
// OK: Authentication
//
// OK: Authorization
//
// OK: Validation
//
// OK: Database Connection
//
// OK: Logging
//
// OK: Error Handling
//
// OK: Utility Functions
//
// OK: API Wrapper
//
// OK: Email Sending
//
// OK: React Components
//
// OK: Express Middleware
//
// OK: Node.js Services

// ==========================================================
// Advantages
// ==========================================================

// OK: Less Code
//
// OK: Easy Maintenance
//
// OK: Easy Testing
//
// OK: Less Bugs
//
// OK: Better Readability
//
// OK: Better Reusability

// ==========================================================
// Common Mistakes
// ==========================================================

// BAD: Copy Paste Programming
//
// BAD: Same Logic in Multiple Files
//
// BAD: Same Validation Everywhere
//
// BAD: Multiple Database Connections
//
// BAD: Duplicate SQL Queries

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
// What is DRY?
//
// DRY stands for
// Don't Repeat Yourself.
//
// Logic should exist
// only once.

// ----------------------------------------------------------

// Q2.
// Why is DRY important?
//
// Easy maintenance.
//
// Less bugs.
//
// Code reuse.

// ----------------------------------------------------------

// Q3.
// Give a real example.
//
// Tax Calculation.
//
// Validation.
//
// Logger.
//
// Authentication.

// ----------------------------------------------------------

// Q4.
// How do we implement DRY?
//
// Functions.
//
// Classes.
//
// Utility Methods.
//
// Common Services.
//
// Shared Components.

// ==========================================================
// Interview Answer
// ==========================================================

// "DRY stands for Don't Repeat Yourself.
//
// It means every piece of business logic
// should exist only once in the codebase.
//
// Instead of duplicating the same code,
// we create reusable functions,
// classes or components.
//
// This makes the software easier to
// maintain, test and extend."

// ==========================================================
// Memory Trick
// ==========================================================

// DRY
//
// Write Once.
//
// Reuse Everywhere.

// ==========================================================
// Difference between DRY and SOLID
// ==========================================================

// DRY
//
// Avoid duplicate code.

// SRP
//
// One Class
//
// One Responsibility.

// OCP
//
// Extend
//
// Don't Modify.

// LSP
//
// Child behaves like Parent.

// ISP
//
// Small Interfaces.

// DIP
//
// Depend on Interfaces.
//
// Not Concrete Classes.

// ==========================================================
// Interview Scenario
// ==========================================================

// Interviewer:
//
// Tomorrow GST changes from
// 18% to 20%.
//
// What will you do?
//
// GOOD ANSWER:
//
// Change only:
//
// calculateTax()
//
// Everything else works automatically.
//
// This follows DRY.