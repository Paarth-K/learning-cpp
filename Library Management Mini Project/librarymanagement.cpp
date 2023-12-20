#include <iostream>
#include <list>
using namespace std;

class Book
{
public:
    string name;
    string author;
    int id;
    int yearOfPublication;

    Book(string bookName, string authorName, int bookYearOfPublication, int bookId)
    {
        name = bookName;
        author = authorName;
        yearOfPublication = bookYearOfPublication;
        id = bookId;
    };
};

class User
{

private:
    string password;

public:
    string name;
    string email;
    User(string userName, string userEmail, string userPassword)
    {
        name = userName;
        email = userEmail;
        password = userPassword;
    };

    bool isSameUser(string usrEmail)
    {
        if (usrEmail == email)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    list<Book *> borrowedBooks;

    string borrowBook(Book *book)
    {
        bool found = (find(borrowedBooks.begin(), borrowedBooks.end(), book) != borrowedBooks.end());
        if (found)
        {
            return "You have already borrowed this book";
        }
        else
        {
            borrowedBooks.push_front(book);
            return book->name + " borrowed successfully";
        }
    };
    string returnBook(Book *book)
    {
        bool found = (find(borrowedBooks.begin(), borrowedBooks.end(), book) != borrowedBooks.end());
        if (found)
        {
            borrowedBooks.remove(book);
            return book->name + " returned successfully";
        }
        else
        {
            return "You have not borrowed this book, so you cannot return it";
        }
     };
    int getNumberOfBooks()
    {
        return borrowedBooks.size();
    };
    bool verifyPassword(string userPassword)
    {
        if (userPassword == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

User *findUser(list<User *> userList, const string &email)
{
    for (User *user : userList)
    {
        if (user->isSameUser(email))
        {
            return user; // return the address of the user object
        }
    }
    return nullptr; // return null if no user is found
};

void handleBookBorrow(list<Book *> bookList, User *user)
{
    int bookId;
    cout << "Enter the id of the book you want to borrow: ";
    cin >> bookId;
    Book *bookPtr = nullptr;
    for (Book *book : bookList)
    {
        if (book->id == bookId)
        {
            bookPtr = book;
            break;
        }
    }
    if (bookPtr != nullptr)
    {
        cout << user->borrowBook(bookPtr) << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
};

void handleBookReturn(list<Book *> bookList, User *user)
{
    int bookId;
    cout << "Enter the id of the book you want to return: ";
    cin >> bookId;
    Book *bookPtr = nullptr;
    for (Book *book : bookList)
    {
        if (book->id == bookId)
        {
            bookPtr = book;
            break;
        }
    }
    if (bookPtr != nullptr)
    {
        cout << user->returnBook(bookPtr) << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
};

void librarySystem(User *user)
{
    Book book1("The Alchemist", "Paulo Coelho", 1988, 1);
    Book book2("The Kite Runner", "Khaled Hosseini", 2003, 2);
    Book book3("The Da Vinci Code", "Dan Brown", 2003, 3);
    Book book4("The Monk Who Sold His Ferrari", "Robin Sharma", 1997, 4);
    Book book5("The God of Small Things", "Arundhati Roy", 1997, 5);
    list<Book *> bookList;
    bookList.push_front(&book1);
    bookList.push_front(&book2);
    bookList.push_front(&book3);
    bookList.push_front(&book4);
    bookList.push_front(&book5);

    cout << '\n'
         << "Welcome to the library " << user->name << "!" << endl;
    while (true)
    {
        string command;
        cout << '\n'
             << "Enter a command (type 'help' to list all commands): ";
        cin >> command;

        if (command == "help")
        {
            cout << "Available commands: " << '\n'
                 << "type '1' to borrow a book" << '\n'
                 << "type '2' to return a book" << '\n'
                 << "type '3' to list all books available" << '\n'
                 << "type '4' to list all books you have borrowed" << '\n'
                 << "type 'exit' to exit" << endl;
            continue;
        }
        else if (command == "1")
        {
            handleBookBorrow(bookList, user);
        }
        else if (command == "2")
        {
            handleBookReturn(bookList, user);
        }
        else if (command == "3")
        {
            cout << "Books available: " << endl;
            for (Book *book : bookList)
            {
                cout << book->id << " - " << book->name << endl;
            }
        }
        else if (command == "4")
        {
            cout << "Books borrowed: " << endl;
            for (Book *book : user->borrowedBooks)
            {
                cout << book->id << " - " << book->name << endl;
            }
        }
        else if (command == "exit")
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
    };
};

int main()
{

    User user1("John", "hi@hi.com", "password!");
    User user2("User", "user@user.com", "passwords");
    User user3("Hi", "y", "y");

    list<User *> userList;
    userList.push_front(&user1);
    userList.push_front(&user2);
    userList.push_front(&user3);

    string inputName;
    cout << "Enter the email of the user: ";
    cin >> inputName;

    User *userPtr = findUser(userList, inputName);
    if (userPtr != nullptr)
    {
        cout << "User found: " << userPtr->name << endl;
        char proceed;
        cout << "Proceed? (y/n): ";
        cin >> proceed;
        if (proceed == 'y')
        {
            string inputPassword;
            cout << "Enter the password of the user: ";
            cin >> inputPassword;
            if (userPtr->verifyPassword(inputPassword))
            {
                cout << "Password verified" << endl;
                librarySystem(userPtr);
            }
            else
            {
                cout << "Password incorrect" << endl;
            }
        }
        else
        {
            cout << "Exiting..." << endl;
        }
    }
    else
    {
        cout << "User not found" << endl;
    }

    return 0;
}