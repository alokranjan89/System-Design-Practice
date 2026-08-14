#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Product
class Product
{
public:
    string name;
    int price;

    Product(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};


// Iterator Interface
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual Product next() = 0;

    virtual ~Iterator() {}
};


// Collection
class ProductCollection
{
private:
    vector<Product> products;

public:
    void addProduct(Product product)
    {
        products.push_back(product);
    }

    Product getProduct(int index)
    {
        return products[index];
    }

    int size()
    {
        return products.size();
    }
};


// Concrete Iterator
class ProductIterator : public Iterator
{
private:
    ProductCollection& collection;
    int index;

public:
    ProductIterator(ProductCollection& collection)
        : collection(collection), index(0)
    {
    }

    bool hasNext() override
    {
        return index < collection.size();
    }

    Product next() override
    {
        return collection.getProduct(index++);
    }
};


// Client
int main()
{
    ProductCollection collection;

    collection.addProduct(Product("Laptop", 50000));
    collection.addProduct(Product("Mouse", 1000));
    collection.addProduct(Product("Keyboard", 2500));

    ProductIterator iterator(collection);

    while (iterator.hasNext())
    {
        Product product = iterator.next();

        cout << product.name << " "
             << product.price << endl;
    }

    return 0;
}