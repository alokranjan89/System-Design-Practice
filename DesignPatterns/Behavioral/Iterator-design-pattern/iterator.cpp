#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Iterator Interface
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;

    virtual ~Iterator() {}
};

// Collection
class BookCollection
{
private:
    vector<string> books;

public:
    void addBook(string book)
    {
        books.push_back(book);
    }

    string getBook(int index)
    {
        return books[index];
    }

    int size()
    {
        return books.size();
    }
};

// Concrete Iterator
class BookIterator : public Iterator
{
private:
    BookCollection& collection;
    int index;

public:
    BookIterator(BookCollection& collection)
        : collection(collection), index(0)
    {
    }

    bool hasNext() override
    {
        return index < collection.size();
    }

    string next() override
    {
        return collection.getBook(index++);
    }
};

int main()
{
    BookCollection collection;

    collection.addBook("C++");
    collection.addBook("Java");
    collection.addBook("Python");

    BookIterator iterator(collection);

    while(iterator.hasNext())
    {
        cout << iterator.next() << endl;
    }

    return 0;
}