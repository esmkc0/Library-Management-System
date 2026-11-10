
#include "Library.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

Library::Library(const string& filename)
        : nextId(1), dataFile(filename) {
    loadBooks();
}

void Library::loadBooks() {
    books.clear();

    ifstream file(dataFile);

    if (!file) {
        books.emplace_back(1, "The Hobbit", "J.R.R. Tolkien");
        books.emplace_back(2, "1984", "George Orwell");
        books.emplace_back(3, "Pride and Prejudice", "Jane Austen");

        nextId = 4;
        return;
    }

    string line;

    while (getline(file, line)) {
        try {
            int id = stoi(line);
            string title;
            string author;

            if (!getline(file, title)) break;
            if (!getline(file, author)) break;
            if (!getline(file, line)) break;

            bool borrowed = (stoi(line) != 0);

            books.emplace_back(id, title, author, borrowed);
        } catch (const exception&) {
            cout << "Warning: Invalid data in books file.\n";
            break;
        }
    }

    nextId = 1;

    for (const Book& book : books) {
        nextId = max(nextId, book.id + 1);
    }
}

void Library::saveBooks() const {
    ofstream file(dataFile);

    if (!file) {
        cout << "Error: Could not save books.\n";
        return;
    }

    for (const Book& book : books) {
        file << book.id << '\n';
        file << book.title << '\n';
        file << book.author << '\n';
        file << book.isBorrowed << '\n';
    }

    cout << "Books saved successfully!\n";
}

void Library::addBook() {
    string title;
    string author;

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter author name: ";
    getline(cin, author);

    if (title.empty() || author.empty()) {
        cout << "Title and author cannot be empty.\n";
        return;
    }

    books.emplace_back(nextId++, title, author);

    cout << "Book added successfully!\n";
}

void Library::viewAllBooks() const {
    cout << "\n===== ALL BOOKS =====\n";

    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    for (const Book& book : books) {
        book.displayInfo();
    }
}

void Library::searchBook() const {
    int bookId;

    cout << "Enter Book ID: ";

    if (!(cin >> bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Book ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const Book& book : books) {
        if (book.id == bookId) {
            cout << "\nBook found!\n";
            book.displayInfo();
            return;
        }
    }

    cout << "Book not found.\n";
}

void Library::borrowBook() {
    int bookId;

    cout << "Enter Book ID: ";

    if (!(cin >> bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Book ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Book& book : books) {
        if (book.id == bookId) {
            if (book.isBorrowed) {
                cout << "Book is already borrowed.\n";
            } else {
                book.isBorrowed = true;
                cout << "Book borrowed successfully!\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void Library::returnBook() {
    int bookId;

    cout << "Enter Book ID: ";

    if (!(cin >> bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Book ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Book& book : books) {
        if (book.id == bookId) {
            if (!book.isBorrowed) {
                cout << "Book is already available.\n";
            } else {
                book.isBorrowed = false;
                cout << "Book returned successfully!\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void Library::deleteBook() {
    int bookId;

    cout << "Enter Book ID: ";

    if (!(cin >> bookId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Book ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == bookId) {
            books.erase(it);
            cout << "Book deleted successfully!\n";
            return;
        }
    }

    cout << "Book not found.\n";
}
