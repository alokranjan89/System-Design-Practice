#include <iostream>
#include <vector>

using namespace std;

class MenuComponent
{
public:
    virtual int getCost() = 0;

    virtual ~MenuComponent() {};
};

class MenuItem : public MenuComponent
{
private:
    int cost;

public:
    MenuItem(int cost) : cost(cost) {}

    int getCost() override
    {
        return cost;
    }
};

class Menu : public MenuComponent
{
private:
    vector<MenuComponent *> children;

public:
    void addItem(MenuComponent *items)
    {
        children.push_back(items);
    }

    int getCost() override
    {
        int total = 0;

        for (auto child : children)
        {
            total += child->getCost();
        }
        return total;
    }
};

int main()
{
    MenuItem pizza(200);
    MenuItem burger(150);
    MenuItem coke(50);
    MenuItem coffee(100);

    Menu drinks;

    drinks.addItem(&coke);
    drinks.addItem(&coffee);

    Menu restaurantMenu;

    restaurantMenu.addItem(&pizza);
    restaurantMenu.addItem(&burger);
    restaurantMenu.addItem(&drinks);

    cout << "Total Cost: "
         << restaurantMenu.getCost()
         << endl;

    return 0;
}