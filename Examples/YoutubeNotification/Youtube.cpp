#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Observer
{
public:
    virtual void update(string videoTitle) = 0;
    virtual ~Observer() {};
};

class Subject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;

    virtual ~Subject() {};
};

class YouTubeChannel : public Subject
{
private:
    vector<Observer *> observers;
    string videoTitle;

public:
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

    void notifyObservers() override
    {
        for (Observer *observer : observers)
        {
            observer->update(videoTitle);
        }
    }
    void uploadVideo(string videoTitle)
    {
        this->videoTitle = videoTitle;
        notifyObservers();
    }
};

class Subscriber : public Observer
{
private:
    string name;

public:
    Subscriber(string name) : name(name) {};

    void update(string videoTitle) override
    {
        cout << name << " received notification: "
             << videoTitle << endl;
    }
};

int main()
{
    YouTubeChannel channel;

    Subscriber alok("Alok");
    Subscriber akash("Akash");
    Subscriber rahul("Rahul");

    channel.addObserver(&alok);
    channel.addObserver(&akash);
    channel.addObserver(&rahul);

    channel.uploadVideo("Observer Design Pattern");

    return 0;
}