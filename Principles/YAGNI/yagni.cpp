#include <iostream>
using namespace std;

// ==========================================================
// YAGNI Principle
// You Aren't Gonna Need It
// ==========================================================

// ==========================================================
// Definition
// ==========================================================

// YAGNI stands for
//
// You Aren't Gonna Need It.
//
// It is a software development principle that states:
//
// "Do not implement features until
// they are actually required."
//
// Build only what the current
// requirements demand.

// ==========================================================
// Simple Meaning
// ==========================================================

// Don't build tomorrow's features today.
//
// Implement only the current requirements.
//
// Future requirements should be implemented
// only when they actually arrive.

// ==========================================================
// Why YAGNI?
// ==========================================================

// Building unnecessary features causes:
//
// BAD: Wasted Development Time
//
// BAD: More Bugs
//
// BAD: Difficult Maintenance
//
// BAD: Larger Codebase
//
// BAD: Unused Code
//
// Instead:
//
// OK: Build only what is required.
//
// OK: Add new features when needed.

// ==========================================================
// BAD DESIGN
// ==========================================================

// Interviewer:
//
// Build Calculator.
//
// Requirements:
//
// Addition
//
// Subtraction
//
// Multiplication
//
// Division
//
// Student builds:
//
// AI Assistant
//
// Voice Commands
//
// Cloud Backup
//
// Graph Plotter
//
// Blockchain
//
// PDF Export
//
// Nobody asked for these.
//
// Violates YAGNI.

// ==========================================================
// GOOD DESIGN
// ==========================================================

// Build only:
//
// Addition
//
// Subtraction
//
// Multiplication
//
// Division
//
// Future features can be added later.

// ==========================================================
// C++ Example
// ==========================================================

// Current Requirement:
//
// Calculate Sum.

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "Addition : " << add(10, 20) << endl;

    return 0;
}

/*

================ OUTPUT =================

Addition : 30

==========================================

*/


// ==========================================================
// BAD EXAMPLE
// ==========================================================

// Interviewer only asked:
//
// Addition
//
// Student writes:
//
// add()
//
// subtract()
//
// multiply()
//
// divide()
//
// squareRoot()
//
// cubeRoot()
//
// logarithm()
//
// trigonometry()
//
// scientificMode()
//
// history()
//
// cloudSync()
//
// Completely unnecessary.
//
// Violates YAGNI.

// ==========================================================
// Code Explanation
// ==========================================================

// add()
//
// Only current requirement.
//
// Nothing extra.
//
// Easy to maintain.
//
// Easy to understand.

// ==========================================================
// Real World Example
// ==========================================================

// Student Management System
//
// Requirement:
//
// Add Student
//
// Delete Student
//
// Update Student
//
// Search Student
//
// Student builds:
//
// AI Recommendation
//
// Face Recognition
//
// Blockchain
//
// Chat
//
// Video Calling
//
// Voice Assistant
//
// None were required.
//
// Violates YAGNI.

// ==========================================================
// Where is YAGNI Used?
// ==========================================================

// OK: Backend APIs
//
// Build only required endpoints.

// ----------------------------------------------------------

// OK: Database
//
// Create only required tables.
//
// Don't create tables
// "just in case".

// ----------------------------------------------------------

// OK: LLD
//
// Design only required classes.
//
// Don't create imaginary classes.

// ----------------------------------------------------------

// OK: Frontend
//
// Build only requested screens.

// ----------------------------------------------------------

// OK: System Design
//
// Avoid over-engineering.

// ==========================================================
// Advantages
// ==========================================================

// OK: Less Code
//
// OK: Faster Development
//
// OK: Easy Maintenance
//
// OK: Less Bugs
//
// OK: Better Focus
//
// OK: Smaller Codebase

// ==========================================================
// Common Mistakes
// ==========================================================

// BAD: Building future features.
//
// BAD: Creating unnecessary classes.
//
// BAD: Creating unnecessary APIs.
//
// BAD: Adding extra database tables.
//
// BAD: Over Engineering.

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
//
// What is YAGNI?
//
// You Aren't Gonna Need It.
//
// Build only what is required today.

// ----------------------------------------------------------

// Q2.
//
// Why is YAGNI important?
//
// Saves time.
//
// Reduces bugs.
//
// Keeps the project simple.

// ----------------------------------------------------------

// Q3.
//
// Give one example.
//
// Calculator.
//
// Parking Lot.
//
// Student Management System.

// ----------------------------------------------------------

// Q4.
//
// Difference between
// KISS and YAGNI?
//
// KISS:
//
// Keep the solution simple.
//
// YAGNI:
//
// Don't build features
// until they're needed.

// ==========================================================
// Interview Answer
// ==========================================================

// "YAGNI stands for
// You Aren't Gonna Need It.
//
// It means developers should
// implement only the features
// required by the current
// requirements.
//
// We should avoid building
// future features based on
// assumptions because they may
// never be needed."

// ==========================================================
// Memory Trick
// ==========================================================

// YAGNI
//
// Don't Build
//
// Tomorrow's Features
//
// Today.

// ==========================================================
// Difference
// ==========================================================

// DRY
//
// Don't Repeat Code.

// ----------------------------------------------------------

// KISS
//
// Keep Solution Simple.

// ----------------------------------------------------------

// YAGNI
//
// Build Only Required Features.

// ----------------------------------------------------------

// SOLID
//
// Better Object-Oriented Design.

// ==========================================================
// Interview Scenario
// ==========================================================

// Interviewer:
//
// Design Parking Lot.
//
// Requirement:
//
// Bike
//
// Car
//
// Student builds:
//
// Bike
//
// Car
//
// Truck
//
// Bus
//
// Helicopter
//
// Drone
//
// Boat
//
// EV Charging
//
// AI Parking Prediction
//
// Blockchain Payment
//
// Wrong.
//
// Build only:
//
// Bike
//
// Car.
//
// Future features can be added later.
//
// That follows YAGNI.