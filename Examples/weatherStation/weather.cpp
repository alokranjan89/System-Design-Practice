#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update(int temperature) = 0;
    virtual ~Observer() {}
};

class Subject
{
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;

    virtual ~Subject() {}
};

class WeatherStation : public Subject
{
private:
    vector<Observer*> observers;
    int temperature;

public:
    void addObserver(Observer* observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override
    {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notifyObservers() override
    {
        for (Observer* observer : observers)
        {
            observer->update(temperature);
        }
    }

    void setTemperature(int temperature)
    {
        this->temperature = temperature;
        notifyObservers();
    }
};

class PhoneDisplay : public Observer
{
public:
    void update(int temperature) override
    {
        cout << "Phone Display: "
             << temperature << "°C" << endl;
    }
};

class TVDisplay : public Observer
{
public:
    void update(int temperature) override
    {
        cout << "TV Display: "
             << temperature << "°C" << endl;
    }
};

class WebsiteDisplay : public Observer
{
public:
    void update(int temperature) override
    {
        cout << "Website Display: "
             << temperature << "°C" << endl;
    }
};

int main()
{
    WeatherStation weatherStation;

    PhoneDisplay phone;
    TVDisplay tv;
    WebsiteDisplay website;

    weatherStation.addObserver(&phone);
    weatherStation.addObserver(&tv);
    weatherStation.addObserver(&website);

    weatherStation.setTemperature(30);

    return 0;
}