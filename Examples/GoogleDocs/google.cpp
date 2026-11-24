
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// ==================================================
// 1. DocumentElement - Abstract Base Class
// ==================================================

class DocumentElement
{
public:
    // Every document element must implement render()
    virtual string render() const = 0;

    virtual ~DocumentElement() = default;
};

// ==================================================
// 2. TextElement - Represents text
// ==================================================

class TextElement : public DocumentElement
{
private:
    string text;

public:
    explicit TextElement(string text)
        : text(move(text))
    {
    }

    string render() const override
    {
        return text;
    }
};

// ==================================================
// 3. ImageElement - Represents an image
// ==================================================

class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    explicit ImageElement(string imagePath)
        : imagePath(move(imagePath))
    {
    }

    string render() const override
    {
        return "[Image: " + imagePath + "]";
    }
};

// ==================================================
// 4. NewLineElement - Represents a new line
// ==================================================

class NewLineElement : public DocumentElement
{
public:
    string render() const override
    {
        return "\n";
    }
};

// ==================================================
// 5. TabSpaceElement - Represents tab spacing
// ==================================================

class TabSpaceElement : public DocumentElement
{
public:
    string render() const override
    {
        return "\t";
    }
};

// ==================================================
// 6. Document - Stores document elements
// ==================================================

class Document
{
private:
    vector<unique_ptr<DocumentElement>> elements;

public:
    // Takes ownership of the document element
    void addElement(unique_ptr<DocumentElement> element)
    {
        if (element)
        {
            elements.push_back(move(element));
        }
    }

    // Renders all elements in sequence
    string render() const
    {
        string result;

        for (const auto& element : elements)
        {
            result += element->render();
        }

        return result;
    }
};

// ==================================================
// 7. Persistence - Abstract Storage Interface
// ==================================================

class Persistence
{
public:
    virtual void save(const string& data) = 0;

    virtual ~Persistence() = default;
};

// ==================================================
// 8. FileStorage - Saves document into a file
// ==================================================

class FileStorage : public Persistence
{
public:
    void save(const string& data) override
    {
        ofstream outFile("document.txt");

        if (!outFile)
        {
            cout << "Error: Unable to open file\n";
            return;
        }

        outFile << data;

        if (!outFile)
        {
            cout << "Error: Unable to write file\n";
            return;
        }

        cout << "Document saved successfully\n";
    }
};

// ==================================================
// 9. DocumentEditor - Coordinates document operations
// ==================================================

class DocumentEditor
{
private:
    Document& document;
    Persistence& storage;

public:
    // Dependency Injection through references
    DocumentEditor(Document& document, Persistence& storage)
        : document(document), storage(storage)
    {
    }

    void addText(string text)
    {
        document.addElement(
            make_unique<TextElement>(move(text))
        );
    }

    void addImage(string imagePath)
    {
        document.addElement(
            make_unique<ImageElement>(move(imagePath))
        );
    }

    void addNewLine()
    {
        document.addElement(
            make_unique<NewLineElement>()
        );
    }

    void addTabSpace()
    {
        document.addElement(
            make_unique<TabSpaceElement>()
        );
    }

    string renderDocument() const
    {
        return document.render();
    }

    void saveDocument()
    {
        storage.save(renderDocument());
    }
};

// ==================================================
// 10. Main Function
// ==================================================

int main()
{
    Document document;
    FileStorage storage;

    DocumentEditor editor(document, storage);

    // Adding content
    editor.addText("Google Docs Example");
    editor.addNewLine();

    editor.addText("This document is rendered and saved.");
    editor.addNewLine();

    editor.addTabSpace();
    editor.addImage("example.png");

    // Rendering document
    cout << "Document Content:\n";
    cout << editor.renderDocument() << endl;

    // Saving document
    editor.saveDocument();

    return 0;
}
