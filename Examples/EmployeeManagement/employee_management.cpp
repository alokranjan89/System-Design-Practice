#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class
class Employee
{
protected:
    int employeeId;
    string name;
    double salary;

public:
    Employee(int employeeId, string name, double salary)
    {
        this->employeeId = employeeId;
        this->name = name;
        this->salary = salary;
    }

    virtual void login()
    {
        cout << name << " logged in." << endl;
    }

    virtual void logout()
    {
        cout << name << " logged out." << endl;
    }

    virtual void work() = 0; // Pure virtual function

    virtual ~Employee() = default;
};

// Developer Class
class Developer : public Employee
{
public:
    Developer(int employeeId, string name, double salary)
        : Employee(employeeId, name, salary)
    {
    }

    void writeCode()
    {
        cout << name << " is writing code." << endl;
    }

    void work() override
    {
        writeCode();
    }
};

// Manager Class
class Manager : public Employee
{
public:
    Manager(int employeeId, string name, double salary)
        : Employee(employeeId, name, salary)
    {
    }

    void assignTask()
    {
        cout << name << " is assigning tasks." << endl;
    }

    void work() override
    {
        assignTask();
    }
};

// Company Class
class Company
{
private:
    string companyName;
    vector<Employee *> employees;

public:
    Company(string companyName)
    {
        this->companyName = companyName;
    }

    void addEmployee(Employee *employee)
    {
        employees.push_back(employee);
    }

    void showEmployees()
    {
        cout << "\nEmployees of " << companyName << endl;
        cout << "---------------------------" << endl;

        for (Employee *emp : employees)
        {
            emp->login();
            emp->work();
            emp->logout();
            cout << endl;
        }
    }

    ~Company()
    {
        for (Employee *emp : employees)
        {
            delete emp;
        }
    }
};

int main()
{
    Company company("OpenAI");

    company.addEmployee(new Developer(101, "Alok", 50000));
    company.addEmployee(new Manager(201, "Rahul", 80000));

    company.showEmployees();

    return 0;
}
