
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <string>
#include <vector>

class Library {
private:
    std::vector<Book> books;
    int nextId;
    std::string dataFile;

public:
    explicit Library(const std::string& filename = "books.txt");

    void addBook();
    void viewAllBooks() const;
    void searchBook() const;
    void borrowBook();
    void returnBook();
    void deleteBook();

    void loadBooks();
    void saveBooks() const;
};

#endif
