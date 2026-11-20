#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
    virtual ~DocumentElement() = default;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imgpath;

public:
    ImageElement(string imgpath)
    {
        this->imgpath = imgpath;
    }
    string render() override
    {
        return "[Image: " + imgpath + "]";
    }
};

class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

class Document
{
private:
    vector<unique_ptr<DocumentElement>> documentelements;

public:
    void addElement(unique_ptr<DocumentElement> element)
    {
        documentelements.push_back(std::move(element));
    }

    string render()
    {
        string result;
        for (const auto& element : documentelements)
        {
            result += element->render();
        }
        return result;
    }
};

class persistence
{
public:
    virtual void save(string data) = 0;
    virtual ~persistence() = default;
};

class FileStorage : public persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error : Unable to open file for writing" << endl;
        }
    }
};

class DocumentEditor
{
private:
    Document *document;
    persistence *storage;

public:
    DocumentEditor(Document *document, persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(make_unique<TextElement>(text));
    }

    void addImage(string imagePath)
    {
        document->addElement(make_unique<ImageElement>(imagePath));
    }

    void addNewLine()
    {
        document->addElement(make_unique<NewLineElement>());
    }
    void TabSpace()
    {
        document->addElement(make_unique<TabSpaceElement>());
    }

    string renderDocument()
    {
        return document->render();
    }

    void saveDocument()
    {
        storage->save(renderDocument());
    }
};

int main()
{
    Document document;
    FileStorage storage;
    DocumentEditor editor(&document, &storage);

    editor.addText("Google Docs example");
    editor.addNewLine();
    editor.addText("This document is rendered and saved to a file.");
    editor.addNewLine();
    editor.addImage("example.png");

    cout << editor.renderDocument();
    editor.saveDocument();

    return 0;
}