// #include <iostream>
// #include <mutex>
// using namespace std;

// Method 1: Lazy initialization using static pointer + mutex
//
// Steps:
// 1. Keep a static pointer named instance.
// 2. Set instance to nullptr at the start.
// 3. When getInstance() is called, first check if object is not created.
// 4. Lock the mutex so only one thread can create the object.
// 5. Check instance again after locking.
// 6. Create the object only once using new Singleton().
// 7. Return the same object address every time.
//
// Advantages:
// - Object is created only when it is needed.
// - Mutex helps make object creation thread-safe.
// - Double check avoids locking after the object is already created.
//
// Disadvantages:
// - Code is longer and more complex.
// - Uses new, so object cleanup needs care.
// - Wrong locking logic can create thread-safety bugs.
//
// class Singleton
// {
// private:
//     static Singleton *instance;
//     static mutex mtx;
//
//     // Private constructor stops direct object creation from outside.
//     Singleton()
//     {
//         cout << "Singleton New Object" << endl;
//     }
//
// public:
//     static Singleton *getInstance()
//     {
//         // First check: if object already exists, return it directly.
//         if (instance == nullptr)
//         {
//             // Lock before creating object, so only one thread enters here.
//             lock_guard<mutex> lock(mtx);
//
//             // Second check: another thread may have created it already.
//             if (instance == nullptr)
//             {
//                 instance = new Singleton();
//             }
//         }
//
//         return instance;
//     }
// };
//
// Singleton *Singleton ::instance = nullptr;
// mutex Singleton::mtx;

// int main()
// {
//     Singleton *s1 = Singleton ::getInstance();
//     Singleton *s2 = Singleton ::getInstance();

//     cout << (s1 == s2) << endl;
// }


// 
#include <iostream>
#include <mutex>

using namespace std;

// Method 2: Eager initialization using static pointer
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
        cout << "Singleton Constrctor Called" << endl;
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
