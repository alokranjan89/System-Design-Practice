/*
Notification
-> Email
-> SMS
-> Push Notification

*/
#include <iostream>
#include <string>

using namespace std;

class NotificationStrategy
{
public:
    virtual void send(string message) = 0;
    virtual ~NotificationStrategy() {}
};

class EmailNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending SMS: " << message << endl;
    }
};

class WhatsAppNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending WhatsApp: " << message << endl;
    }
};

class NotificationService
{
private:
    NotificationStrategy *strategy;

public:
    NotificationService(NotificationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void setStrategy(NotificationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void notify(string message)
    {
        strategy->send(message);
    }
};

int main()
{
    EmailNotification email;
    SMSNotification sms;
    WhatsAppNotification whatsapp;

    NotificationService notify(&email);

    notify.notify("Order Placed");

    notify.setStrategy(&sms);
    notify.notify("Order Placed");

    notify.setStrategy(&whatsapp);
    notify.notify("Order Placed");

    return 0;
}