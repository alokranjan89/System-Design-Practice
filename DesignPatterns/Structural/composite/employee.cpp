#include <iostream>
#include <vector>
using namespace std;

// Composite Design Pattern:
// A common interface is used by both leaf and composite objects.
// This allows the client code to treat individual employees and groups of employees uniformly.
class EmployeeComponenet
{
public:
    virtual int getSalary() = 0;
    virtual ~EmployeeComponenet() = default;
};

// Leaf node in the composite hierarchy.
// An employee has no child objects and directly returns its own salary.

class Employee : public EmployeeComponenet
{
private:
    int salary;

public:
    Employee(int salary) : salary(salary) {}

    int getSalary() override
    {
        return salary;
    }
};

// Composite node in the hierarchy.
// A manager can contain other employees or managers.
// The total salary is computed by adding the manager's own salary
// and the salaries of all nested employees under them.
class Manager : public EmployeeComponenet
{
private:
    int salary;

    vector<EmployeeComponenet *> children;

public:
    Manager(int salary) : salary(salary) {}

    void add(EmployeeComponenet *employee)
    {
        children.push_back(employee);
    }

    int getSalary() override
    {

        int total = salary;

        for (auto child : children)
        {
            total += child->getSalary();
        }

        return total;
    }
};

// Main idea of the Composite Pattern:
// The client does not need to know whether it is dealing with a single employee
// or a manager containing many employees. Both are treated as EmployeeComponenet.
int main() {

    // Employees
    Employee e1(40000);
    Employee e2(60000);
    Employee e3(30000);


    // Manager 2
    Manager m2(80000);

    m2.add(&e3);


    // Manager 1
    Manager m1(100000);

    m1.add(&e1);
    m1.add(&e2);
    m1.add(&m2);


    // Calculate total salary
    cout << "Total salary under Manager 1: "
         << m1.getSalary()
         << endl;


    return 0;
}