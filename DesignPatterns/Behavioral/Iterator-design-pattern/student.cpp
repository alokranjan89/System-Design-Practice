#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;

    virtual ~Iterator() {}
};

class StudentCollection
{
private:
    vector<string> students;

public:
    void addStudent(string student)
    {
        students.push_back(student);
    }

    string getStudent(int index)
    {
        return students[index];
    }

    int size()
    {
        return students.size();
    }
};

class StudentIterator : public Iterator
{
private:
    StudentCollection& collection;
    int index;

public:
    StudentIterator(StudentCollection& collection)
        : collection(collection), index(0)
    {
    }

    bool hasNext() override
    {
        return index < collection.size();
    }

    string next() override
    {
        return collection.getStudent(index++);
    }
};

int main()
{
    StudentCollection collection;

    collection.addStudent("Alok");
    collection.addStudent("Akash");
    collection.addStudent("Vikash");
    collection.addStudent("Ajay");

    StudentIterator iterator(collection);

    while (iterator.hasNext())
    {
        cout << iterator.next() << endl;
    }

    return 0;
}