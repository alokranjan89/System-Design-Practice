#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Observer Interface
class ISubscriber
{
public:
    virtual void update(string videoTitle) = 0;
    virtual ~ISubscriber() = default;
};

// Subject Interface
class IChannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unsubscribe(ISubscriber *subscriber) = 0;
    virtual void notify() = 0;

    virtual ~IChannel() = default;
};

// Concrete Observer
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
        cout << name
             << " received notification: New video uploaded - "
             << videoTitle << endl;
    }
};

// Concrete Subject
class YouTubeChannel : public IChannel
{
private:
    string channelName;
    string latestVideo;
    vector<ISubscriber *> subscribers;

public:
    YouTubeChannel(string name)
    {
        channelName = name;
    }

    void subscribe(ISubscriber *subscriber) override
    {
        subscribers.push_back(subscriber);
        cout << "A subscriber joined " << channelName << endl;
    }

    void unsubscribe(ISubscriber *subscriber) override
    {
        subscribers.erase(
            remove(subscribers.begin(), subscribers.end(), subscriber),
            subscribers.end());

        cout << "A subscriber left " << channelName << endl;
    }

    void notify() override
    {
        for (ISubscriber *subscriber : subscribers)
        {
            subscriber->update(latestVideo);
        }
    }

    void uploadVideo(string title)
    {
        latestVideo = title;

        cout << "\n=====================================\n";
        cout << "[Video] " << channelName << " uploaded: "
             << latestVideo << endl;
        cout << "=====================================\n";

        notify();
    }
};

int main()
{
    // Create YouTube Channel
    YouTubeChannel channel("CodeWithAlok");

    // Create Subscribers
    Subscriber s1("Alok");
    Subscriber s2("Rahul");
    Subscriber s3("Aman");

    // Subscribe
    channel.subscribe(&s1);
    channel.subscribe(&s2);
    channel.subscribe(&s3);

    // Upload First Video
    channel.uploadVideo("Observer Design Pattern in C++");

    cout << "\n---------------------------------\n";

    // Rahul unsubscribes
    channel.unsubscribe(&s2);

    cout << "Rahul unsubscribed.\n";

    cout << "\n---------------------------------\n";

    // Upload Second Video
    channel.uploadVideo("Factory Design Pattern in C++");

    return 0;
}