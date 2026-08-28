#include <iostream>

using namespace std;

class Payment
{
public:
    virtual void pay() = 0;

    virtual ~Payment() {}
};

class OldPaymentGateway
{
public:
    void makePayment()
    {
        cout << "Payment completed using old gateway" << endl;
    }
};

class PaymentAdapter : public Payment
{
private:
    OldPaymentGateway& oldPaymentGateway;

public:
    PaymentAdapter(OldPaymentGateway& oldPaymentGateway)
        : oldPaymentGateway(oldPaymentGateway)
    {
    }

    void pay() override
    {
        oldPaymentGateway.makePayment();
    }
};

void processPayment(Payment* payment)
{
    payment->pay();
}

int main()
{
    OldPaymentGateway oldGateway;

    PaymentAdapter adapter(oldGateway);

    processPayment(&adapter);

    return 0;
}