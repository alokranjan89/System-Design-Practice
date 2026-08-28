#include <iostream>
using namespace std;

class Printer
{
public:
    virtual void print() = 0;

    virtual ~Printer() {}
};

class OldPrinter
{
public:
    void printDocument()
    {
        cout << "Printing document..." << endl;
    }
};

class PrinterAdapter : public Printer
{
private:
    OldPrinter& oldPrinter;

public:
    PrinterAdapter(OldPrinter& oldPrinter)
        : oldPrinter(oldPrinter)
    {
    }

    void print() override
    {
        oldPrinter.printDocument();
    }
};

void printFile(Printer* printer)
{
    printer->print();
}

int main()
{
    OldPrinter oldPrinter;

    PrinterAdapter adapter(oldPrinter);

    printFile(&adapter);

    return 0;
}