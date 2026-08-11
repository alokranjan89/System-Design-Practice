#include <iostream>
using namespace std;

// ==========================================================
// KISS Principle
// Keep It Simple, Stupid
// ==========================================================

// ==========================================================
// Definition
// ==========================================================

// KISS stands for
//
// Keep It Simple, Stupid.
//
// It is a software design principle that states:
//
// "Software should be designed and implemented
// in the simplest possible way while still
// satisfying the current requirements."
//
// Avoid unnecessary complexity.

// ==========================================================
// Simple Meaning
// ==========================================================

// Solve today's problem
// with today's requirements.
//
// Don't overcomplicate the solution.
//
// Simple Code
//
// Easy to Read
//
// Easy to Debug
//
// Easy to Maintain

// ==========================================================
// Why KISS?
// ==========================================================

// Complex code causes:
//
// BAD: More Bugs
//
// BAD: Difficult Debugging
//
// BAD: Difficult Maintenance
//
// BAD: Difficult Testing
//
// BAD: Difficult Understanding
//
// Simple code gives:
//
// OK: Better Readability
//
// OK: Better Maintainability
//
// OK: Easy Testing
//
// OK: Easy Debugging

// ==========================================================
// BAD DESIGN
// ==========================================================

// Interviewer:
//
// Build Calculator.
//
// Requirement:
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
// AI
//
// Voice Assistant
//
// Blockchain
//
// Cloud Sync
//
// PDF Export
//
// Graph Plotter
//
// None of these were required.
//
// Violates KISS.

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
// That's enough.
//
// Follows KISS.

// ==========================================================
// BAD CODE
// ==========================================================

// Finding maximum of two numbers.

// int findMax(int a,int b)
// {
//      vector<int> arr;
//
//      arr.push_back(a);
//
//      arr.push_back(b);
//
//      sort(arr.begin(),arr.end());
//
//      return arr[1];
// }
//
// Works.
//
// But unnecessarily complex.

// ==========================================================
// GOOD CODE
// ==========================================================

int findMax(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

// ==========================================================
// Another Example
// ==========================================================

// BAD

// bool isAdult(int age)
// {
//     if(age>=18)
//     {
//          return true;
//     }
//     else
//     {
//          return false;
//     }
// }

// GOOD

bool isAdult(int age)
{
    return age >= 18;
}

// ==========================================================
// Main
// ==========================================================

int main()
{
    cout << "Maximum : " << findMax(20, 35) << endl;

    cout << "Adult : " << isAdult(22) << endl;

    return 0;
}

/*

================ OUTPUT =================

Maximum : 35

Adult : 1

==========================================

*/


// ==========================================================
// Code Explanation
// ==========================================================

// findMax()
//
// Finds the larger number.
//
// Uses the simplest possible logic.
//
// No extra data structures.
//
// No sorting.
//
// No unnecessary complexity.

// ----------------------------------------------------------

// isAdult()
//
// Returns true if age >=18.
//
// Avoids unnecessary if-else.
//
// Easier to read.

// ==========================================================
// Real World Example
// ==========================================================

// TV Remote
//
// GOOD
//
// Power
//
// Volume
//
// Channel
//
// Mute
//
// Easy to use.

// ----------------------------------------------------------

// BAD
//
// AI
//
// Camera
//
// Bitcoin
//
// Weather
//
// Facebook
//
// Calculator
//
// Shopping
//
// Too complicated.
//
// Violates KISS.

// ==========================================================
// Where is KISS Used?
// ==========================================================

// OK: Function Design
//
// OK: Class Design
//
// OK: API Design
//
// OK: LLD
//
// OK: System Design
//
// OK: Database Queries
//
// OK: Algorithms
//
// OK: UI Design

// ==========================================================
// Advantages
// ==========================================================

// OK: Easy to Read
//
// OK: Easy to Understand
//
// OK: Easy to Maintain
//
// OK: Easy to Debug
//
// OK: Easy to Test
//
// OK: Less Bugs

// ==========================================================
// Common Mistakes
// ==========================================================

// BAD: Over Engineering
//
// BAD: Unnecessary Design Patterns
//
// BAD: Huge Classes
//
// BAD: Huge Functions
//
// BAD: Clever but Confusing Code

// ==========================================================
// Interview Questions
// ==========================================================

// Q1.
//
// What is KISS?
//
// KISS stands for
// Keep It Simple, Stupid.
//
// Design software using the
// simplest possible solution.

// ----------------------------------------------------------

// Q2.
//
// Why is KISS important?
//
// Because simple code is
// easier to understand,
// maintain,
// test,
// and debug.

// ----------------------------------------------------------

// Q3.
//
// Does KISS mean writing
// fewer lines of code?
//
// NO.
//
// It means writing
// simpler and more readable code.

// ----------------------------------------------------------

// Q4.
//
// Give one real-world example.
//
// TV Remote.
//
// Calculator.
//
// Student Management System.

// ==========================================================
// Interview Answer
// ==========================================================

// "KISS stands for
// Keep It Simple, Stupid.
//
// It means software should
// be designed using the
// simplest solution that
// satisfies the current
// requirements.
//
// We should avoid unnecessary
// complexity because simple
// code is easier to understand,
// maintain,
// test,
// and debug."

// ==========================================================
// Memory Trick
// ==========================================================

// KISS
//
// Keep
//
// It
//
// Simple
//
// Stupid
//
// Simple Code
//
// Professional Code

// ==========================================================
// Difference
// ==========================================================

// DRY
//
// Don't Repeat Yourself.
//
// Avoid duplicate code.

// ----------------------------------------------------------

// KISS
//
// Keep It Simple.
//
// Avoid unnecessary complexity.

// ----------------------------------------------------------

// YAGNI
//
// You Aren't Gonna Need It.
//
// Don't build features
// until they're actually required.

// ----------------------------------------------------------

// SOLID
//
// Design Better
//
// Classes and Objects.

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
// Helicopter
//
// Boat
//
// Drone
//
// EV Charging
//
// AI Parking Prediction
//
// Blockchain Payment
//
// Bad.
//
// Build only what was asked.
//
// That follows KISS.