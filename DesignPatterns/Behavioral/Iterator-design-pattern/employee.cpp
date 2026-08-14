#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Employee
class Employee
{
private:
    string name;
    int id;

public:
    Employee(string name, int id)
        : name(name), id(id)
    {
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }
};


// 2. Iterator Interface
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual Employee next() = 0;

    virtual ~Iterator() {}
};


// 3. Employee Collection
class EmployeeCollection
{
private:
    vector<Employee> employees;

public:
    void addEmployee(Employee employee)
    {
        employees.push_back(employee);
    }

    Employee getEmployee(int index)
    {
        return employees[index];
    }

    int size()
    {
        return employees.size();
    }
};


// 4. Concrete Iterator
class EmployeeIterator : public Iterator
{
private:
    EmployeeCollection& collection;
    int index;

public:
    EmployeeIterator(EmployeeCollection& collection)
        : collection(collection), index(0)
    {
    }

    bool hasNext() override
    {
        return index < collection.size();
    }

    Employee next() override
    {
        return collection.getEmployee(index++);
    }
};


// 5. Client
int main()
{
    EmployeeCollection collection;

    collection.addEmployee(Employee("Alok", 101));
    collection.addEmployee(Employee("Rahul", 102));
    collection.addEmployee(Employee("Priya", 103));
    collection.addEmployee(Employee("Ankit", 104));

    EmployeeIterator iterator(collection);

    while (iterator.hasNext())
    {
        Employee employee = iterator.next();

        cout << employee.getName()
             << " "
             << employee.getId()
             << endl;
    }

    return 0;
}