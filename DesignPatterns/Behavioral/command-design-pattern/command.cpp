#include <iostream>
using namespace std;

// 1. Receiver
// Knows HOW to perform the actual work
class Light
{
public:
    void turnOn()
    {
        cout << "Light is ON" << endl;
    }

    void turnOff()
    {
        cout << "Light is OFF" << endl;
    }
};


// 2. Command Interface
// Defines WHAT every command must provide
class Command
{
public:
    virtual void execute() = 0;

    virtual ~Command() {}
};


// 3. Concrete Command - Turn ON
class TurnOnCommand : public Command
{
private:
    Light& light;

public:
    TurnOnCommand(Light& light)
        : light(light)
    {
    }

    void execute() override
    {
        light.turnOn();
    }
};


// 4. Concrete Command - Turn OFF
class TurnOffCommand : public Command
{
private:
    Light& light;

public:
    TurnOffCommand(Light& light)
        : light(light)
    {
    }

    void execute() override
    {
        light.turnOff();
    }
};


// 5. Invoker
// Triggers the command
class RemoteControl
{
private:
    Command* command;

public:
    RemoteControl(Command* command)
        : command(command)
    {
    }

    void setCommand(Command* command)
    {
        this->command = command;
    }

    void pressButton()
    {
        command->execute();
    }
};


// 6. Client
int main()
{
    // Create Receiver
    Light light;

    // Create Commands
    TurnOnCommand turnOn(light);
    TurnOffCommand turnOff(light);

    // Create Invoker with TurnOnCommand
    RemoteControl remote(&turnOn);

    // Execute ON command
    remote.pressButton();

    // Change command
    remote.setCommand(&turnOff);

    // Execute OFF command
    remote.pressButton();

    return 0;
}