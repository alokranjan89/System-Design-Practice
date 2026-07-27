#include <iostream>
#include <vector>
using namespace std;


class Animal {
protected:
    int id;
    string name;
    int age;

public:
    Animal(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    virtual void eat()
    {
        cout << name << " is eating." << endl;
    }

    virtual void sleep()
    {
        cout << name << " is sleeping." << endl;
    }

    virtual void makeSound() = 0;

    virtual ~Animal() {}
};


class Dog : public Animal {

public:
    Dog(int id, string name, int age)
        : Animal(id, name, age) {}

    void bark()
    {
        cout << name << " is barking." << endl;
    }

    void makeSound() override
    {
        bark();
    }
};

class Cat : public Animal {

public:
    Cat(int id, string name, int age)
        : Animal(id, name, age) {}

    void meow()
    {
        cout << name << " is meowing." << endl;
    }

    void makeSound() override
    {
        meow();
    }
};


class Owner {

private:
    int ownerId;
    string ownerName;

    vector<Animal*> animals;

public:

    Owner(int id, string name)
    {
        ownerId = id;
        ownerName = name;
    }

    void adoptAnimal(Animal* animal)
    {
        animals.push_back(animal);
    }

    void showAnimals()
    {
        cout << "\nOwner : " << ownerName << endl;

        for (Animal* animal : animals)
        {
            animal->makeSound();
        }
    }
};


int main()
{
    Owner owner(1, "Alok");

    Dog* dog = new Dog(101, "Bruno", 3);
    Cat* cat = new Cat(102, "Kitty", 2);

    owner.adoptAnimal(dog);
    owner.adoptAnimal(cat);

    dog->eat();
    dog->sleep();

    cat->eat();

    owner.showAnimals();

    delete dog;
    delete cat;

    return 0;
}