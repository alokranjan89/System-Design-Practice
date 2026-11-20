
#include <iostream>

class PaymentMethod {
public:
    virtual void pay(double amount) const = 0;
    virtual ~PaymentMethod() = default;
};

class CardPayment : public PaymentMethod {
public:
    void pay(double amount) const override {
        std::cout << "Paid $" << amount << " by card.\n";
    }
};

int main() {
    CardPayment card;
    const PaymentMethod& paymentMethod = card;
    paymentMethod.pay(25.00);
}

// Practice: add a different PaymentMethod implementation.
