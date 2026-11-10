
# Library Management System

A console-based Library Management System developed in C++17 using Object-Oriented Programming (OOP) principles.

## Features

- Add new books
- View all books
- Search for books by ID
- Borrow books
- Return borrowed books
- Delete books
- Save and load book data using file handling
- Input validation

## Technologies Used

- C++17
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- File I/O
- CMake
- CLion

## Project Structure

LibraryManagementSystem/
- main.cpp - Main menu and application flow
- Book.h - Book class declaration
- Book.cpp - Book class implementation
- Library.h - Library class declaration
- Library.cpp - Library management operations
- CMakeLists.txt - Build configuration
- README.md - Project documentation

## How to Run

1. Clone the repository.
2. Open the project in CLion or another CMake-compatible IDE.
3. Build the project using CMake.
4. Run the LibraryManagementSystem executable.

## Data Persistence

Book records are stored in a local text file named `books.txt`.

The application loads saved book records at startup and saves them when the user selects "Save and Exit".

If no data file exists, the application starts with three sample books.

## Future Improvements

- Search books by title or author
- Add user accounts
- Track borrowing history
- Add automated unit tests
