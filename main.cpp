#include <iostream>
#include <limits>
#include "Library.h"

using namespace std;

int main() {
    Library library;
    int choice = 0;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add a Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Borrow a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Delete a Book\n";
        cout << "7. Save and Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                library.saveBooks();
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.viewAllBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.borrowBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                library.deleteBook();
                break;

            case 7:
                library.saveBooks();
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}