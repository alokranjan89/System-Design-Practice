#include <iostream>
using namespace std;

// ========================================================
// Step 1: Strategy Interface (Abstract Class)
// ========================================================

// This is the common interface.
// Every payment method MUST implement pay().

class PaymentStrategy
{
public:
    // Pure virtual function
    virtual void pay(int amount) = 0;

    // Virtual destructor
    virtual ~PaymentStrategy() {}
};

// ========================================================
// Step 2: Concrete Strategy 1
// ========================================================

class CreditCardPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid ₹" << amount
             << " using Credit Card" << endl;
    }
};

// ========================================================
// Step 3: Concrete Strategy 2
// ========================================================

class UpiPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid ₹" << amount
             << " using UPI" << endl;
    }
};

// ========================================================
// Step 4: Concrete Strategy 3
// ========================================================

class PaypalPayment : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid ₹" << amount
             << " using PayPal" << endl;
    }
};

// ========================================================
// Step 5: Context Class
// ========================================================

class ShoppingCart
{
private:

    // Context doesn't know which payment method it has.
    // It only knows it has SOME PaymentStrategy.

    PaymentStrategy* strategy;

public:

    // Constructor

    ShoppingCart(PaymentStrategy* strategy)
    {
        this->strategy = strategy;
    }

    // Optional: Change payment method at runtime
    void setPaymentStrategy(PaymentStrategy* strategy)
    {
        this->strategy = strategy;
    }

    // Checkout

    void checkout(int amount)
    {
        strategy->pay(amount);
    }
};

// ========================================================
// Main
// ========================================================

int main()
{
    // Create strategies

    CreditCardPayment creditCard;
    UpiPayment upi;
    PaypalPayment paypal;

    // Create shopping cart with Credit Card

    ShoppingCart cart(&creditCard);

    cart.checkout(1000);

    // Change strategy

    cart.setPaymentStrategy(&upi);

    cart.checkout(2000);

    // Change again

    cart.setPaymentStrategy(&paypal);

    cart.checkout(5000);

    return 0;
}