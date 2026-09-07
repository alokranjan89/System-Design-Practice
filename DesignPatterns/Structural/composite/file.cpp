#include <iostream>
#include <vector>

using namespace std;

class FileSystem
{
public:
    virtual int getSize() = 0;

    virtual ~FileSystem() {}
};

class File : public FileSystem
{
private:
    int size;

public:
    File(int size) : size(size) {}

    int getSize() override
    {
        return size;
    }
};

class Folder : public FileSystem
{
private:
    vector<FileSystem *> children;

public:
    void addFile(FileSystem *items)
    {
        children.push_back(items);
    }

    void removeFile(FileSystem *item)
    {
        children.erase(
            remove(children.begin(), children.end(), item),
            children.end());
    }
    int getSize() override
    {
        int total = 0;

        for (auto child : children)
        {
            total += child->getSize();
        }
        return total;
    }
};