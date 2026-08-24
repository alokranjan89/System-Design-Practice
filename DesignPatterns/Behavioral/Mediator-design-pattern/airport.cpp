#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Plane;

class Mediator
{
public:
    virtual void sendMessage(string message, Plane* sender) = 0;

    virtual ~Mediator() {}
};

class Plane
{
private:
    string name;
    Mediator* mediator;

public:
    Plane(string name, Mediator* mediator)
        : name(name), mediator(mediator)
    {
    }

    void requestLanding()
    {
        mediator->sendMessage(name + " wants to land", this);
    }

    void receiveMessage(string message)
    {
        cout << name << " received: "
             << message << endl;
    }
};

class ControlTower : public Mediator
{
private:
    vector<Plane*> planes;

public:
    void addPlane(Plane* plane)
    {
        planes.push_back(plane);
    }

    void sendMessage(string message, Plane* sender) override
    {
        cout << "Control Tower: " << message << endl;

        for (Plane* plane : planes)
        {
            if (plane != sender)
            {
                plane->receiveMessage(message);
            }
        }
    }
};

int main()
{
    ControlTower tower;

    Plane planeA("Plane A", &tower);
    Plane planeB("Plane B", &tower);
    Plane planeC("Plane C", &tower);

    tower.addPlane(&planeA);
    tower.addPlane(&planeB);
    tower.addPlane(&planeC);

    planeA.requestLanding();

    return 0;
}