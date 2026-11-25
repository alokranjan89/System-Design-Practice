
// #include <iostream>
// using namespace std;

// class Singleton
// {
// private:
//     static Singleton *instance;

//     Singleton()
//     {
//         cout << "Singleton is Created" << endl;
//     }

// public:
//     static Singleton* getInstance()
//     {
//         return instance;
//     }
// };

// // Eager initialization
// Singleton* Singleton::instance = new Singleton();

// int main()
// {
//     Singleton* s1 = Singleton::getInstance();
//     Singleton* s2 = Singleton::getInstance();

//     cout << (s1 == s2) << endl;

//     return 0;
// }

/// Lazy Instuialization

#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton created" << endl;
    }

public:
    Singleton(const Singleton&) = delete; // Delete copy constructor
    Singleton &operator=(const Singleton &) = delete;

    static Singleton &getInstance()
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
}