
#include "Book.h"
#include <iostream>

Book::Book(int bookId,
           std::string bookTitle,
           std::string bookAuthor,
           bool borrowed)
        : id(bookId),
          title(bookTitle),
          author(bookAuthor),
          isBorrowed(borrowed) {
}

void Book::displayInfo() const {
    std::cout << "\nBook ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Status: "
              << (isBorrowed ? "Borrowed" : "Available")
              << std::endl;
    std::cout << "------------------------" << std::endl;
}

