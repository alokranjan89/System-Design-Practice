#include <iostream>
using namespace std;

// =====================
// Abstract Products
// =====================

class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() {}
};

// =====================
// Windows Products
// =====================

class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Windows Checkbox\n";
    }
};

// =====================
// Mac Products
// =====================

class MacButton : public Button {
public:
    void paint() override {
        cout << "Mac Button\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Mac Checkbox\n";
    }
};

// =====================
// Abstract Factory
// =====================

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;

    virtual ~GUIFactory() {}
};

// =====================
// Concrete Factories
// =====================

class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }

    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

// =====================
// Client
// =====================

int main() {

    int choice;

    cout << "1. Windows\n";
    cout << "2. Mac\n";

    cin >> choice;

    GUIFactory* factory;

    if(choice == 1)
        factory = new WindowsFactory();
    else
        factory = new MacFactory();

    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();

    button->paint();
    checkbox->paint();

    delete button;
    delete checkbox;
    delete factory;

    return 0;
}