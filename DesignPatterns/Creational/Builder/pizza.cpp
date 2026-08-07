#include <iostream>
#include <vector>

using namespace std;

class Pizza
{
public:
    string size;
    bool cheese;
    bool mushroom;
    bool paneer;
    bool olives;

    void display()
    {
        cout << "Size      : " << size << endl;
        cout << "Cheese    : " << (cheese ? "Yes" : "No") << endl;
        cout << "Mushroom  : " << (mushroom ? "Yes" : "No") << endl;
        cout << "Paneer    : " << (paneer ? "Yes" : "No") << endl;
        cout << "Olives    : " << (olives ? "Yes" : "No") << endl;
    }
};

class PizzaBuilder
{
private:
    Pizza pizza;

public:
    PizzaBuilder &setSize(string size)
    {
        pizza.size = size;
        return *this;
    }

    PizzaBuilder &addCheese(bool cheese)
    {
        pizza.cheese = cheese;
        return *this;
    }

    PizzaBuilder &addMushroom(bool mushroom)
    {
        pizza.mushroom = mushroom;
        return *this;
    }

    PizzaBuilder &addPaneer(bool paneer)
    {
        pizza.paneer = paneer;
        return *this;
    }

    PizzaBuilder &addOlives(bool olives)
    {
        pizza.olives = olives;
        return *this;
    }

    Pizza build()
    {
        return pizza;
    }
};

int main()
{
    Pizza vegPizza = PizzaBuilder()
                         .setSize("Large")
                         .addCheese(true)
                         .addMushroom(true)
                         .addPaneer(true)
                         .addOlives(false)
                         .build();

    vegPizza.display();

    cout << endl;
    Pizza simplePizza = PizzaBuilder()
                            .setSize("Medium")
                            .addCheese(true)
                            .addMushroom(false)
                            .addPaneer(false)
                            .addOlives(false)
                            .build();

    simplePizza.display();

    return 0;
}