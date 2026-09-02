#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
    string name;
    int health;
    int level;

public:
    // Constructor
    Character(string name, int health, int level)
        : name(name), health(health), level(level)
    {
    }

    // Clone method
    Character* clone()
    {
        return new Character(*this);
    }

    // Setter
    void setHealth(int health)
    {
        this->health = health;
    }

    // Display character
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

int main()
{
    // Original object
    Character warrior("Warrior", 100, 5);

    cout << "Original Character:" << endl;
    warrior.display();

    cout << "\nCloning character...\n" << endl;

    // Clone the original
    Character* warrior2 = warrior.clone();

    cout << "Cloned Character:" << endl;
    warrior2->display();

    // Modify clone
    warrior2->setHealth(50);

    cout << "\nAfter modifying clone:\n" << endl;

    cout << "Original:" << endl;
    warrior.display();

    cout << "\nClone:" << endl;
    warrior2->display();

    // Check if they are different objects
    cout << "\nAre they the same object? "
         << (&warrior == warrior2) << endl;

    delete warrior2;

    return 0;
}