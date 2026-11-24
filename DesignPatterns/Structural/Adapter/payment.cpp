#include <iostream>
#include <string>

using namespace std;

class IPayment
{
public:
    virtual void pay(double amount) = 0;
    virtual ~IPayment() {};
};

class RazorPay
{
public:
    void makePayment(double amount)
    {
        cout << "Payment Through RazorPay: " << amount << endl;
    }
};

class RazorpayAdapter : public IPayment
{
private:
    RazorPay razorpay;

public:
    void pay(double amount)
    {
        razorpay.makePayment(amount);
    }
};

class Client
{
public:
    void makeTransaction(IPayment *payment, double amount)
    {
        payment->pay(amount);
    }
};

int main()
{
    RazorpayAdapter adapter;

    Client client;

    client.makeTransaction(&adapter, 500);
    return 0;
}