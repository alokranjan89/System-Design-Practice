#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;

public:
    Account(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Deposit amount must be positive\n";
            return;
        }

        balance += amount;
        cout << "Deposited : " << amount << endl;
    }

    virtual bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdraw amount must be positive\n";
            return false;
        }

        if (amount > balance)
        {
            cout << "Insufficient Balance\n";
            return false;
        }

        balance -= amount;
        cout << "Withdrawn : " << amount << endl;
        return true;
    }

    string getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    virtual void accountType() = 0;

    virtual ~Account() {}
};

class SavingAccount : public Account
{
public:
    SavingAccount(string accountNumber, double balance)
        : Account(accountNumber, balance)
    {
    }

    void accountType() override
    {
        cout << "Saving Account\n";
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(string accountNumber, double balance)
        : Account(accountNumber, balance)
    {
    }

    void accountType() override
    {
        cout << "Current Account\n";
    }
};

class AtmCard
{
private:
    string cardNumber;
    string expiryDate;
    int pin;

public:
    AtmCard(string cardNumber, string expiryDate, int pin)
    {
        this->cardNumber = cardNumber;
        this->expiryDate = expiryDate;
        this->pin = pin;
    }

    bool verifyPin(int enteredPin)
    {
        return pin == enteredPin;
    }

    string getCardNumber()
    {
        return cardNumber;
    }

    string getExpiryDate()
    {
        return expiryDate;
    }
};

class Customer
{
private:
    int customerId;
    string name;
    AtmCard card;
    Account *account;

public:
    Customer(int customerId, string name, AtmCard card, Account *account)
        : card(card)
    {
        this->customerId = customerId;
        this->name = name;
        this->account = account;
    }

    int getCustomerId()
    {
        return customerId;
    }

    string getName()
    {
        return name;
    }

    AtmCard &getCard()
    {
        return card;
    }

    Account *getAccount()
    {
        return account;
    }
};

class Transaction
{
private:
    int transactionId;
    string type;
    double amount;

public:
    Transaction(int transactionId, string type, double amount)
    {
        this->transactionId = transactionId;
        this->type = type;
        this->amount = amount;
    }

    void display()
    {
        cout << "\nTransaction Id : " << transactionId << endl;
        cout << "Type : " << type << endl;
        cout << "Amount : " << amount << endl;
    }
};

class Receipt
{
public:
    void print(double balance)
    {
        cout << "------ RECEIPT ------\n";
        cout << "Available Balance : " << balance << endl;
        cout << "---------------------\n";
    }
};

class ATM
{
private:
    Receipt receipt;
    int nextTransactionId;

public:
    ATM()
    {
        nextTransactionId = 1;
    }

    bool authenticate(Customer &customer, int enteredPin)
    {
        return customer.getCard().verifyPin(enteredPin);
    }

    void deposit(Customer &customer, double amount)
    {
        Account *account = customer.getAccount();
        account->deposit(amount);

        Transaction transaction(nextTransactionId++, "Deposit", amount);
        transaction.display();
        receipt.print(account->getBalance());
    }

    void withdraw(Customer &customer, double amount)
    {
        Account *account = customer.getAccount();

        if (account->withdraw(amount))
        {
            Transaction transaction(nextTransactionId++, "Withdraw", amount);
            transaction.display();
            receipt.print(account->getBalance());
        }
    }

    void checkBalance(Customer &customer)
    {
        Account *account = customer.getAccount();

        cout << "\nAccount Number : " << account->getAccountNumber() << endl;
        cout << "Customer Name : " << customer.getName() << endl;
        cout << "Balance : " << account->getBalance() << endl;
    }
};

int main()
{
    SavingAccount account("ACC1001", 5000);
    AtmCard card("CARD001", "12/30", 1234);
    Customer customer(1, "Alok", card, &account);

    ATM atm;

    if (atm.authenticate(customer, 1234))
    {
        cout << "Authentication Successful\n";

        atm.checkBalance(customer);
        atm.deposit(customer, 1000);
        atm.withdraw(customer, 2000);
        atm.checkBalance(customer);
    }
    else
    {
        cout << "Invalid PIN\n";
    }

    return 0;
}
