
#include <iostream>
#include <string>
#include <memory>

using namespace std;

// 1. Common Interface (Component)
class Character
{
public:
    virtual string getAbilities() const = 0;

    virtual ~Character() = default;
};

// 2. Concrete Component
class Mario : public Character
{
public:
    string getAbilities() const override
    {
        return "Mario";
    }
};

// 3. Abstract Decorator
class CharacterDecorator : public Character
{
protected:
    unique_ptr<Character> character;

public:
    CharacterDecorator(unique_ptr<Character> c)
        : character(move(c)) {}
};

// 4. Concrete Decorator: HeightUp
class HeightUp : public CharacterDecorator
{
public:
    HeightUp(unique_ptr<Character> c)
        : CharacterDecorator(move(c)) {}

    string getAbilities() const override
    {
        return character->getAbilities() + " with HeightUp";
    }
};

// 5. Concrete Decorator: GunPowerUp
class GunPowerUp : public CharacterDecorator
{
public:
    GunPowerUp(unique_ptr<Character> c)
        : CharacterDecorator(move(c)) {}

    string getAbilities() const override
    {
        return character->getAbilities() + " with GunPowerUp";
    }
};

// 6. Concrete Decorator: StarPowerUp
class StarPowerUp : public CharacterDecorator
{
public:
    StarPowerUp(unique_ptr<Character> c)
        : CharacterDecorator(move(c)) {}

    string getAbilities() const override
    {
        return character->getAbilities() + " with StarPowerUp";
    }

    ~StarPowerUp()
    {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

// 7. Main Function
int main()
{
    // Basic Mario
    unique_ptr<Character> mario = make_unique<Mario>();

    cout << "Basic Character: "
         << mario->getAbilities() << endl;

    // Add HeightUp
    mario = make_unique<HeightUp>(move(mario));

    cout << "After HeightUp: "
         << mario->getAbilities() << endl;

    // Add GunPowerUp
    mario = make_unique<GunPowerUp>(move(mario));

    cout << "After GunPowerUp: "
         << mario->getAbilities() << endl;

    // Add StarPowerUp
    mario = make_unique<StarPowerUp>(move(mario));

    cout << "After StarPowerUp: "
         << mario->getAbilities() << endl;

    return 0;
}
