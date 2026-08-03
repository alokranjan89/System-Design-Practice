#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* instance;

    // Private constructor
    Singleton()
    {
        cout << "Object Created\n";
    }

public:

    static Singleton* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new Singleton();
        }

        return instance;
    }

    void show()
    {
        cout << "Hello from Singleton\n";
    }
};

// Static member definition
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();

    s1->show();

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
}