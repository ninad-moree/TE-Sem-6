#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(const string &title, const string &author, int year)
        : title(title), author(author), year(year) {}
};

class LibrarySystem {
private:
    vector<Book> books;

public:
    void addBook(const string &title, const string &author, int year) {
        books.emplace_back(title, author, year);
        cout << "Book added successfully.\n";
    }

    void searchBook(const string &title) {
        for (const auto &book : books)  {
            if (book.title == title) {
                displayBookInfo(book);
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayAllBooks() {
        if (books.empty())
            cout << "No books in the library.\n";
        else {
            cout << "Library Books:\n";
            for (const auto &book : books) 
                displayBookInfo(book);
        }
    }

private:
    void displayBookInfo(const Book &book) {
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Year: " << book.year << "\n\n";
    }
};

int main() {
    LibrarySystem library;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a book\n";
        cout << "2. Search for a book\n";
        cout << "3. Display all books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        switch (choice) {
            case 1: {
                string title, author;
                int year;

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter author name: ";
                getline(cin, author);

                cout << "Enter publication year: ";
                cin >> year;

                library.addBook(title, author, year);
                break;
            }
        case 2: {
            string title;
            cout << "Enter book title to search: ";
            getline(cin, title);
            library.searchBook(title);
            break;
        }
        case 3:
            library.displayAllBooks();
            break;
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
