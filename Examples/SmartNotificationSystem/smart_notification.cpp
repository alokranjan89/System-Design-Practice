#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class NotificationStrategy
{
public:
    virtual void send(string message) = 0;
    virtual ~NotificationStrategy() {};
};

class EmailNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending Email: " << message << endl;
    }
};

class SmsNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public NotificationStrategy
{
public:
    void send(string message) override
    {
        cout << "Sending Push Notification: " << message << endl;
    }
};

class Observer
{
public:
    virtual void update(string message) = 0;
    virtual ~Observer() {};
};

class EmailUser : public Observer
{
public:
    void update(string message) override
    {
        cout << "Email User received: " << message << endl;
    }
};

class MobileUser : public Observer
{
public:
    void update(string message) override
    {
        cout << "Mobile User received: " << message << endl;
    }
};

class NotificationSubject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers(string message) = 0;

    virtual ~NotificationSubject() {}
};

class NotificationService : public NotificationSubject
{
private:
    NotificationStrategy *strategy;
    vector<Observer *> observers;

public:
    NotificationService(NotificationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void addObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end());
    }

    void notifyObservers(string message) override
    {
        for (Observer *observer : observers)
        {
            observer->update(message);
        }
    }

    void setStrategy(NotificationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void sendNotification(string message)
    {
        strategy->send(message);
        notifyObservers(message);
    }
};

int main()
{
    EmailNotification emailStrategy;
    SmsNotification smsStrategy;
    PushNotification pushStrategy;

    EmailUser emailUser;
    MobileUser mobileUser;

    NotificationService service(&emailStrategy);

    service.addObserver(&emailUser);
    service.addObserver(&mobileUser);

    service.sendNotification("Your order has been shipped");

    service.setStrategy(&smsStrategy);
    service.sendNotification("Your order is out for delivery");

    service.setStrategy(&pushStrategy);
    service.sendNotification("Your order has been delivered");

    return 0;
}