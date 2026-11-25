#include <iostream>
using namespace std;

class Light
{
public:
    void turnOn()
    {
        cout << "Light is ON" << endl;
    }
};

class Fan
{
public:
    void start()
    {
        cout << "Fan is running" << endl;
    }
};

class TV
{
public:
    void turnOn()
    {
        cout << "TV is ON" << endl;
    }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class LightCommand : public Command
{
private:
    Light& light;

public:
    LightCommand(Light& light) : light(light) {}

    void execute() override
    {
        light.turnOn();
    }
};

class FanStartCommand : public Command
{
private:
    Fan& fan;

public:
    FanStartCommand(Fan& fan) : fan(fan) {}

    void execute() override
    {
        fan.start();
    }
};

class TVOnCommand : public Command
{
private:
    TV& tv;

public:
    TVOnCommand(TV& tv) : tv(tv) {}

    void execute() override
    {
        tv.turnOn();
    }
};

class SmartRemote
{
private:
    Command* command;

public:
    SmartRemote(Command* command) : command(command) {}

    void setCommand(Command* command)
    {
        this->command = command;
    }

    void pressButton()
    {
        command->execute();
    }
};

int main()
{
    Light light;
    Fan fan;
    TV tv;

    LightCommand lightCommand(light);
    FanStartCommand fanCommand(fan);
    TVOnCommand tvCommand(tv);

    SmartRemote remote(&lightCommand);

    remote.pressButton();

    remote.setCommand(&fanCommand);
    remote.pressButton();

    remote.setCommand(&tvCommand);
    remote.pressButton();

    return 0;
}