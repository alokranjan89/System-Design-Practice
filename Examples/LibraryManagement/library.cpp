#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User
{
protected:
    int userId;
    string name;

public:
    User(int userId, string name)
        : userId(userId), name(name)
    {
    }

    virtual void displayRole() = 0;
    virtual ~User() = default;
};

class Student : public User
{
public:
    Student(int userId, string name) : User(userId, name)
    {
    }

    void borrowBook()
    {
        cout << name << " borrowed a book." << endl;
    }

    void returnBook()
    {
        cout << name << "returned a book." << endl;
    }
    void displayRole() override
    {
        cout << "Role : Student" << endl;
    }
};

class Librarian : public User
{
public:
    Librarian(int userId, string name) : User(userId, name)
    {
    }
    void addBook()
    {
        cout << name << " added a book." << endl;
    }
    void removeBook()
    {
        cout << name << " removed a book." << endl;
    }
    void issueBook()
    {
        cout << name << " issued a book." << endl;
    }

    void displayRole() override
    {
        cout << "Role : Librarian" << endl;
    }
};

class Book
{
private:
    int bookId;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int bookId, string title, string author)
        : bookId(bookId),
          title(title),
          author(author),
          isAvailable(true)
    {
    }

    void displayBook()
    {
        cout << "Book ID : " << bookId << endl;
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Available : "
             << (isAvailable ? "Yes" : "No")
             << endl;
    }
};

class Library
{
private:
    string libraryName;
    vector<Book *> books;
    vector<User *> users;

public:
    Library(string libraryName)
        : libraryName(libraryName)
    {
    }

    void addBook(Book *book)
    {
        books.push_back(book);
        cout << "Book Added Successfully." << endl;
    }

    void registerUser(User *user)
    {
        users.push_back(user);
        cout << "User Registered Successfully." << endl;
    }

    void showBooks()
    {
        cout << "\nBooks in Library\n";

        for (Book *book : books)
        {
            book->displayBook();
            cout << endl;
        }
    }

    void showUsers()
    {
        cout << "\nRegistered Users\n";

        for (User *user : users)
        {
            user->displayRole();
        }
    }
};

int main()
{
    // Create Library
    Library library("Central Library");

    // Create Books
    Book *book1 = new Book(101, "Clean Code", "Robert C. Martin");
    Book *book2 = new Book(102, "Design Patterns", "GoF");

    // Create Users
    Student *student = new Student(1, "Alok");
    Librarian *librarian = new Librarian(2, "Rahul");

    // Register Users
    library.registerUser(student);
    library.registerUser(librarian);
    
    // Add Books
    library.addBook(book1);
    library.addBook(book2);

    cout << "\n========================\n";

    // Student Operations
    student->displayRole();
    student->borrowBook();
    student->returnBook();

    cout << "\n========================\n";

    // Librarian Operations
    librarian->displayRole();
    librarian->addBook();
    librarian->removeBook();
    librarian->issueBook();

    cout << "\n========================\n";

    // Display Books
    library.showBooks();

    cout << "\n========================\n";

    // Display Users
    library.showUsers();

    return 0;
}
