
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

    Book(int bookId,
         std::string bookTitle,
         std::string bookAuthor,
         bool borrowed = false);

    void displayInfo() const;
};

#endif
