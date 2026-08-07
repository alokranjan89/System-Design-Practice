#include <iostream>
using namespace std;

// ======================================================
// Product
// ======================================================

// Product: The object being built by the Builder.
// In this example, `Computer` is the product with optional features like CPU, RAM, SSD, GPU, RGB, and WiFi.
class Computer
{
public:
    string cpu;
    int ram;
    int ssd;
    bool gpu;
    bool rgb;
    bool wifi;

    void display()
    {
        cout << "\nComputer Configuration\n";
        cout << "----------------------\n";
        cout << "CPU  : " << cpu << endl;
        cout << "RAM  : " << ram << " GB" << endl;
        cout << "SSD  : " << ssd << " GB" << endl;
        cout << "GPU  : " << (gpu ? "Yes" : "No") << endl;
        cout << "RGB  : " << (rgb ? "Yes" : "No") << endl;
        cout << "WiFi : " << (wifi ? "Yes" : "No") << endl;
    }
};

// ======================================================
// Builder
// ======================================================

// Builder: Constructs the product step by step.
// Each setter configures the internal `Computer` instance and returns the builder for chaining.
class ComputerBuilder
{
private:
    Computer computer;

public:

    ComputerBuilder& setCPU(string cpu)
    {
        computer.cpu = cpu;
        return *this;
    }

    ComputerBuilder& setRAM(int ram)
    {
        computer.ram = ram;
        return *this;
    }

    ComputerBuilder& setSSD(int ssd)
    {
        computer.ssd = ssd;
        return *this;
    }

    ComputerBuilder& setGPU(bool gpu)
    {
        computer.gpu = gpu;
        return *this;
    }

    ComputerBuilder& setRGB(bool rgb)
    {
        computer.rgb = rgb;
        return *this;
    }

    ComputerBuilder& setWiFi(bool wifi)
    {
        computer.wifi = wifi;
        return *this;
    }

    Computer build()
    {
        return computer;
    }
};

// ======================================================
// Important Notes
// ======================================================

// - The Builder pattern is useful when an object has many optional parameters.
// - The builder provides a fluent interface for readable configuration chaining.
// - `build()` returns the configured product after all options are set.
// - This example mutates an internal `Computer` instance before returning it.
// - For production usage, validate required values or consider an immutable product.

// ======================================================
// Main
// ======================================================

int main()
{
    Computer gamingPC = ComputerBuilder()
                            .setCPU("Intel i9")
                            .setRAM(32)
                            .setSSD(1000)
                            .setGPU(true)
                            .setRGB(true)
                            .setWiFi(true)
                            .build();

    gamingPC.display();

    cout << endl;

    Computer officePC = ComputerBuilder()
                            .setCPU("Intel i5")
                            .setRAM(16)
                            .setSSD(512)
                            .setGPU(false)
                            .setRGB(false)
                            .setWiFi(true)
                            .build();

    officePC.display();

    return 0;
}