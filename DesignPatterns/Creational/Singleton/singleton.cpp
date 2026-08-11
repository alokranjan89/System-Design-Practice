#include <iostream>

using namespace std;

// Singleton using eager initialization with a static pointer.
//
// Steps:
// 1. Keep a static pointer named instance.
// 2. Create the Singleton object before main() starts.
// 3. Make the constructor private so outside code cannot create another object.
// 4. getInstance() only returns the already-created object.
// 5. Every call receives the same object address.
//
// Advantages:
// - Simple getInstance() logic.
// - No mutex is needed because the object is created before use.
// - Same instance is available immediately.
//
// Disadvantages:
// - Object is created even if the program never uses it.
// - Uses new, so object cleanup needs care.
// - Startup can become heavier if the object is expensive to create.

class Singleton
{
private:
    // Static pointer stores the only object of this class.
    static Singleton *instance;

    // Private constructor prevents creating objects directly in main().
    Singleton()
    {
        cout << "Singleton Constructor Called" << endl;
    }

public:
    static Singleton *getInstance()
    {
        // Return the object that was already created below.
        return instance;
    }
};

// Object is created before main() starts.
Singleton *Singleton ::instance = new Singleton();

int main()
{
    // Both pointers get the same Singleton object address.
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    // Prints 1 because s1 and s2 point to the same object.
    cout << (s1 == s2) << endl;
}
