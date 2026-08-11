#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//============================
// Observer Interface
//============================

class ISubscriber
{
public:
    virtual void update(string videoTitle) = 0;
    virtual ~ISubscriber() = default;
};

//============================
// Observable Interface
//============================

class IChannel
{
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notify() = 0;

    virtual ~IChannel() = default;
};

//============================
// Concrete Observable
//============================

class YouTubeChannel : public IChannel
{
private:
    string channelName;
    string latestVideo;

    vector<ISubscriber*> subscribers;

public:

    YouTubeChannel(string name)
    {
        channelName = name;
    }

    void subscribe(ISubscriber* subscriber) override
    {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber) override
    {
        subscribers.erase(
            remove(subscribers.begin(),
                   subscribers.end(),
                   subscriber),
            subscribers.end());
    }

    void notify() override
    {
        for (ISubscriber* subscriber : subscribers)
        {
            subscriber->update(latestVideo);
        }
    }

    void uploadVideo(string title)
    {
        latestVideo = title;

        cout << "\n[Video] "
             << channelName
             << " uploaded : "
             << latestVideo
             << endl;

        notify();
    }
};

//============================
// Concrete Observer
//============================

class Subscriber : public ISubscriber
{
private:
    string name;

public:

    Subscriber(string name)
    {
        this->name = name;
    }

    void update(string videoTitle) override
    {
        cout << "[Notification] "
             << name
             << " received notification : "
             << videoTitle
             << endl;
    }
};

//============================
// Main
//============================

int main()
{
    YouTubeChannel channel("CodeWithAlok");

    Subscriber s1("Rahul");
    Subscriber s2("Aman");
    Subscriber s3("Priya");

    channel.subscribe(&s1);
    channel.subscribe(&s2);
    channel.subscribe(&s3);

    channel.uploadVideo("Observer Design Pattern");

    cout << "\nAman unsubscribed.\n";

    channel.unsubscribe(&s2);

    channel.uploadVideo("Factory Design Pattern");

    return 0;
}