#include <iostream>

using namespace std;

class Database
{
private:
    Database()
    {
        cout << "Database Created";
    }

public:
    // Because we want to call it without already having a Database object:
    static Database &getInstance()
    {
        static Database instance;
        return instance;
    }

    void connect()
    {
        cout << "Database connected1" << endl;
    }

    void disconnect()
    {
        cout << "Database disconnected1" << endl;
    }

    void executeQuery(string query)
    {
        cout << "Executing: " << query << endl;
    }
};

int main()
{
    Database &db1 = Database::getInstance();
    Database &db2 = Database::getInstance();

    db1.connect();
    db2.connect();

    db1.executeQuery("SELECT * FROM users");
    db2.executeQuery("SELECT * FROM users");

    db1.disconnect();
    db2.disconnect();
}

// Meyers' Singleton is a way to implement the Singleton Design Pattern in modern C++.

// The goal of Singleton is to ensure that a class has only one instance throughout the application and provide a way to access that instance.

// In Meyers' Singleton, I make the constructor private so that objects cannot be created directly from outside the class.

// Then I provide a public static `getInstance()` method. Inside this method, I create a function-local static object:

// `static Database instance;`

// Because the object is static, it is created only once. On the first call to `getInstance()`, the object is created, and on subsequent calls, the same object is returned.

// I return it by reference:


// `return instance;`

// This allows all callers to work with the same object without creating copies.

// One important advantage of Meyers' Singleton is that since C++11, initialization of a function-local static variable is thread-safe. Therefore, we don't need to manually use a mutex or double-checked locking.

// For example, if two parts of the application call `Database::getInstance()`, both receive a reference to the same Database object.

// So the key idea is: private constructor + static local instance + public static access method.

// If interviewer asks "Why static?"

// Say:

// "I use static so the local object is created only once and its lifetime lasts until the program terminates. Every subsequent call gets the same object."

// If interviewer asks "Why return reference?"

// Say:

// "I return a reference because I want the caller to access the same object directly, without creating a copy and without dealing with a null pointer."

// If interviewer asks "Is it thread-safe?"

// Say:

// "Yes. Since C++11, initialization of a function-local static variable is guaranteed to be thread-safe."