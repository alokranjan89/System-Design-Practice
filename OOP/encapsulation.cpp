#include <iostream>

class BankAccount {
public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit must be positive.\n";
            return;
        }
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const { return balance; }

private:
    double balance;
};

int main() {
    BankAccount account(100);
    account.deposit(50);
    account.withdraw(25);
    std::cout << "Balance: " << account.getBalance() << '\n';
}

// Practice: reject a negative starting balance and add a transfer operation.
