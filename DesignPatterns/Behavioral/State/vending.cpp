#include <iostream>
using namespace std;

class VendingMachine;

class State
{
public:
    virtual void insertMoney(VendingMachine* machine) = 0;
    virtual void selectProduct(VendingMachine* machine) = 0;
    virtual void dispense(VendingMachine* machine) = 0;

    virtual ~State() {}
};

class NoMoneyState : public State
{
public:
    void insertMoney(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};

class HasMoneyState : public State
{
public:
    void insertMoney(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};

class ProductSelectedState : public State
{
public:
    void insertMoney(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};

class VendingMachine
{
private:
    State* noMoneyState;
    State* hasMoneyState;
    State* productSelectedState;
    State* currentState;

public:
    VendingMachine()
    {
        noMoneyState = new NoMoneyState();
        hasMoneyState = new HasMoneyState();
        productSelectedState = new ProductSelectedState();
        currentState = noMoneyState;
    }

    ~VendingMachine()
    {
        delete noMoneyState;
        delete hasMoneyState;
        delete productSelectedState;
    }

    State* getNoMoneyState()
    {
        return noMoneyState;
    }

    State* getHasMoneyState()
    {
        return hasMoneyState;
    }

    State* getProductSelectedState()
    {
        return productSelectedState;
    }

    void setState(State* newState)
    {
        currentState = newState;
    }

    void insertMoney()
    {
        currentState->insertMoney(this);
    }

    void selectProduct()
    {
        currentState->selectProduct(this);
    }

    void dispense()
    {
        currentState->dispense(this);
    }
};

void NoMoneyState::insertMoney(VendingMachine* machine)
{
    cout << "Money inserted" << endl;
    machine->setState(machine->getHasMoneyState());
}

void NoMoneyState::selectProduct(VendingMachine*)
{
    cout << "Please insert money first" << endl;
}

void NoMoneyState::dispense(VendingMachine*)
{
    cout << "Please insert money first" << endl;
}

void HasMoneyState::insertMoney(VendingMachine*)
{
    cout << "Money already inserted" << endl;
}

void HasMoneyState::selectProduct(VendingMachine* machine)
{
    cout << "Product selected" << endl;
    machine->setState(machine->getProductSelectedState());
}

void HasMoneyState::dispense(VendingMachine*)
{
    cout << "Please select a product first" << endl;
}

void ProductSelectedState::insertMoney(VendingMachine*)
{
    cout << "Please wait, product is already selected" << endl;
}

void ProductSelectedState::selectProduct(VendingMachine*)
{
    cout << "Product already selected" << endl;
}

void ProductSelectedState::dispense(VendingMachine* machine)
{
    cout << "Product dispensed" << endl;
    machine->setState(machine->getNoMoneyState());
}

int main()
{
    VendingMachine machine;

    machine.selectProduct();
    machine.insertMoney();
    machine.dispense();
    machine.selectProduct();
    machine.insertMoney();
    machine.selectProduct();
    machine.dispense();

    return 0;
}
