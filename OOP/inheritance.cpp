#include <iostream>

class Vehicle {
public:
    explicit Vehicle(int wheels) : wheels(wheels) {}
    virtual ~Vehicle() = default;

    int getWheels() const { return wheels; }

private:
    int wheels;
};

class Bicycle : public Vehicle {
public:
    Bicycle() : Vehicle(2) {}
};

int main() {
    Bicycle bicycle;
    std::cout << "Bicycle wheels: " << bicycle.getWheels() << '\n';
}

// Practice: add a Car derived from Vehicle with four wheels.
