// #include <iostream>
// using namespace std;

// class Singleton
// {
// private:
//     static Singleton *instance;
//     Singleton()
//     {
//         cout << "Singleton Called." << endl;
//     }

// public:
//     static Singleton *getInstance()
//     {
//         if (instance == nullptr)
//         {
//             instance = new Singleton();
//         }
//         return instance;
//     }
// };

// Singleton *Singleton::instance = nullptr;

// int main()
// {
//     Singleton *s1 = Singleton ::getInstance();
//     Singleton *s2 = Singleton ::getInstance();

//     cout << (s1 == s2) << endl;
// }

// Notes:
// Method: getInstance() checks whether instance is null. If it is null, it
// creates the object; later calls return the same pointer.
// Advantages: Simple, lazy initialization, and creates the object only when needed.
// Disadvantages: Not thread-safe and requires manual memory management.

// #include <iostream>
// #include <mutex>
// using namespace std;

// class Singleton
// {
// private:
//     static Singleton *instance;
//     static mutex mtx;

//     Singleton()
//     {
//         cout << "Singleton Called." << endl;
//     }

// public:
//     static Singleton *getInstance()
//     {
//         if (instance == nullptr)
//         {
//             lock_guard<mutex> lock(mtx);
//             if (instance == nullptr)
//             {
//                 instance = new Singleton();
//             }
//         }
//         return instance;
//     }
// };

// Singleton *Singleton::instance = nullptr;
// mutex Singleton ::mtx;

// int main()
// {
//     Singleton *s1 = Singleton ::getInstance();
//     Singleton *s2 = Singleton ::getInstance();

//     cout << (s1 == s2) << endl;
// }

// Notes:
// Method: The first null check avoids locking after initialization. If the
// object is not ready, a mutex is acquired and the second check prevents
// another thread from creating a duplicate object.
// Advantages: Supports concurrent initialization when locking is implemented correctly.
// Disadvantages: More complex, slower because of locking, and difficult to implement safely.

// Eager initialization

// #include <iostream>
// #include <mutex>
// using namespace std;
//
// class Singleton
// {
// private:
//     static Singleton *instance;
//
//     Singleton()
//     {
//         cout << "Singleton Called." << endl;
//     }
//
// public:
//     static Singleton *getInstance()
//     {
//         return instance;
//     }
// };
//
// Singleton *Singleton::instance = new Singleton();
//
// int main()
// {
//     Singleton *s1 = Singleton ::getInstance();
//     Singleton *s2 = Singleton ::getInstance();
//
//     cout << (s1 == s2) << endl;
// }

// Notes:
// Method: The static data member is initialized before main(). getInstance()
// only returns the already-created pointer.
// Advantages: Simple, thread-safe during static initialization, and does not need a mutex.
// Disadvantages: Creates the object even if it is never used and may increase startup cost.

#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton created\n";
    }

public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
};

int main()
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    cout << (&s1 == &s2) << endl;

    return 0;
}

// Notes:
// Method: The constructor is private, so callers cannot create objects directly.
// The function-local static object is created once on the first call, and every
// later call returns a reference to that same object.
// Advantages: Lazy, thread-safe in C++11 and later, and automatically manages object lifetime.
// Disadvantages: The object usually remains alive until program shutdown and is still global state.