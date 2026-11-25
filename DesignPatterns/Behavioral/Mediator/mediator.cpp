#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User;

class Mediator
{
public:
    virtual void sendMessage(string message, User *sender) = 0;
    virtual ~Mediator() {}
};

class User
{
private:
    string name;
    Mediator *mediator;

public:
    User(string name, Mediator *mediator)
        : name(name), mediator(mediator)
    {
    }

    void send(string message)
    {
        mediator->sendMessage(message, this);
    }

    void receive(string message)
    {
        cout << name << " received: " << message << endl;
    }
};

class ChatRoom : public Mediator
{
private:
    vector<User *> users;

public:
    void addUser(User *user)
    {
        users.push_back(user);
    }

    void sendMessage(string message, User *sender) override
    {
        for (User *user : users)
        {
            if (user != sender)
            {
                user->receive(message);
            }
        }
    }
};

int main()
{
    ChatRoom chatRoom;

    User alok("Alok", &chatRoom);
    User akash("Akash", &chatRoom);
    User rahul("Rahul", &chatRoom);

    chatRoom.addUser(&alok);
    chatRoom.addUser(&akash);
    chatRoom.addUser(&rahul);

    alok.send("Hello everyone");

    akash.send("Hi Alok");

    return 0;
}