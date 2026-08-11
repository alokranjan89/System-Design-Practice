#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Cloneable (aka Prototype) interface
// Any object that can be cloned should implement this.
class Cloneable {
public:
    virtual Cloneable* clone() const = 0;
    virtual ~Cloneable() {}
};

// NPC is a concrete prototype with clone support.
class NPC : public Cloneable {
public:
    string name;
    int health;
    int attack;
    int defense;

    // Heavy constructor simulates expensive setup.
    NPC(const string& name, int health, int attack, int defense) {
        // call database
        // complex calc
        this->name = name; 
        this->health = health; 
        this->attack = attack; 
        this->defense = defense;
        cout << "Setting up template NPC '" << name << "'\n";
    }

    // Copy constructor used by clone().
    // This performs a shallow copy of the NPC fields.
    // Here shallow copy is enough because the fields are plain values and
    // std::string owns its own storage. If NPC held raw pointers, a deep copy
    // would need to duplicate the pointed-to data instead of just copying
    // the pointer values.
    NPC(const NPC& other) {
        name = other.name;
        health = other.health;
        attack = other.attack;
        defense = other.defense;
        cout << "Cloning NPC '" << name << "'\n";
    }

    // The clone method required by Prototype.
    // It uses the copy constructor to make a new object.
    // This is a shallow clone for this example's fields.
    Cloneable* clone() const override {
        return new NPC(*this);
    }

    // Print NPC state for debugging.
    void describe() {
        cout << "NPC " << name  << " [HP=" << health  << " ATK=" << attack 
             << " DEF=" << defense << "]\n";
    }

    // Setters allow customizing each clone independently.
    void setName(const string& n) { 
        name = n;
    }
    void setHealth(int h) { 
        health = h;
    }
    void setAttack(int a) {
         attack = a; 
    }
    void setDefense(int d){ 
        defense = d;
    }
};

int main() {
    // 1) Build one "heavy" template NPC only once.
    NPC* alien = new NPC("Alien", 30, 5, 2);

    // 2) Clone that template instead of recreating from scratch.
    NPC* alienCopied1 = dynamic_cast<NPC*>(alien->clone());
    alienCopied1->describe();

    // 3) Tweak the new clone without changing the original.
    NPC* alienCopied2 = dynamic_cast<NPC*>(alien->clone());
    alienCopied2->setName("Powerful Alien");
    alienCopied2->setHealth(50);
    alienCopied2->describe();

    // cleanup cloned and original NPCs.
    delete alien;
    delete alienCopied1;
    delete alienCopied2;
}

// SHALLOW COPY && DEEP COPY
