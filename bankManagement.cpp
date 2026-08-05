#include <iostream>
#include <vector>
#include <string>

using namespace std;

//==============================
// Base Class
//==============================

class Account
{
protected:
    string accountNumber;
    double balance;

public:
    Account(string accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance)
    {
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << amount << " deposited into Account "
             << accountNumber << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << amount << " withdrawn from Account "
                 << accountNumber << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    virtual void checkBalance()
    {
        cout << "Account Number : " << accountNumber
             << " | Balance : " << balance << endl;
    }

    virtual ~Account() = default;
};

//==============================
// Savings Account
//==============================

class SavingsAccount : public Account
{
public:
    SavingsAccount(string accountNumber, double balance)
        : Account(accountNumber, balance)
    {
    }
};

//==============================
// Current Account
//==============================

class CurrentAccount : public Account
{
public:
    CurrentAccount(string accountNumber, double balance)
        : Account(accountNumber, balance)
    {
    }
};

//==============================
// Customer
//==============================

class Customer
{
private:
    int customerId;
    string name;
    vector<Account *> accounts;

public:
    Customer(int customerId, string name)
        : customerId(customerId), name(name)
    {
    }

    void addAccount(Account *account)
    {
        accounts.push_back(account);
    }

    void showAccounts()
    {
        cout << "\nCustomer : " << name << endl;

        for (Account *account : accounts)
        {
            account->checkBalance();
        }
    }

    ~Customer()
    {
        for (Account *account : accounts)
        {
            delete account;
        }
    }
};

//==============================
// Bank
//==============================

class Bank
{
private:
    string bankName;
    vector<Customer *> customers;

public:
    Bank(string bankName)
        : bankName(bankName)
    {
    }

    void addCustomer(Customer *customer)
    {
        customers.push_back(customer);
    }

    void showCustomers()
    {
        cout << "\n========== " << bankName
             << " ==========\n";

        for (Customer *customer : customers)
        {
            customer->showAccounts();
        }
    }

    ~Bank()
    {
        for (Customer *customer : customers)
        {
            delete customer;
        }
    }
};

//==============================
// Main
//==============================

int main()
{
    Bank bank("State Bank");

    Customer *c1 = new Customer(101, "Alok");
    Customer *c2 = new Customer(102, "Rahul");

    c1->addAccount(new SavingsAccount("SB1001", 10000));
    c1->addAccount(new CurrentAccount("CA1001", 25000));

    c2->addAccount(new SavingsAccount("SB1002", 5000));

    bank.addCustomer(c1);
    bank.addCustomer(c2);

    bank.showCustomers();

    return 0;
}