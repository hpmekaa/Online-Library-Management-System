#include "Admin.h"
#include "Book.h"
#include "User.h"
#include "Transaction.h"
#include "Library.h"
#include "TransactionReport.h"

int main() {
    // Create a library object named "Mars Library"
    Library marsLibrary("Mars Library");
    
    // Check if the library file exists, if not, create a new library
    std::ifstream libraryFile("library.txt");
    if (libraryFile.is_open()) {
        marsLibrary.loadFromFile("library.txt");
        libraryFile.close();
    } else {
        std::cout << "No existing library file found. Creating a new library." << std::endl;
    }

    // ASCII art for the menu title
    std::string title = R"(
 __  __                   ___        _ _
|  \/  | __ _ _ __ ___   / _ \ _ __ | (_)_ __   ___
| |\/| |/ _` | '__/ __| | | | | '_ \| | | '_ \ / _ \
| |  | | (_| | |  \__ \ | |_| | | | | | | | | |  __/
|_|  |_|\__,_|_|  |___/  \___/|_| |_|_|_|_| |_|\___|
| |   (_) |__  _ __ __ _ _ __ _   _
| |   | | '_ \| '__/ _` | '__| | | |
| |___| | |_) | | | (_| | |  | |_| |
|_____|_|_.__/|_|  \__,_|_|   \__, |
/ ___| _   _ ___| |_ ___ _|___/__
\___ \| | | / __| __/ _ \ '_ ` _ \
 ___) | |_| \__ \ ||  __/ | | | | |
|____/ \__, |___/\__\___|_| |_| |_|
       |___/)";

    // ASCII art for the menu
    std::string menu = R"(
+-----------------------+
| 1.  Add Book          |
| 2.  Remove Book       |
| 3.  Add User          |
| 4.  Remove User       |
| 5.  Borrow Book       |
| 6.  Return Book       |
| 7.  Reward User       |
| 8.  Reward Admin      |
| 9.  View Books        |
| 10. View Users        |
| 11. View Transactions |
| 12. Exit              |
+-----------------------+
Enter your choice: )";

    // Vector to store pointers to users
    std::vector<User*> users;
    std::string userFilename = "users.txt";

    // Load users from file if it exists
    std::ifstream userFile(userFilename);
    if (userFile.is_open()) {
        int numUsers;
        userFile >> numUsers;
        userFile.ignore(); // Ignore newline character

        for (int i = 0; i < numUsers; i++) {
            User* user = new User("", 0.0f, 0);
            user->loadFromFile(userFilename + "." + std::to_string(i + 1));
            users.push_back(user);
        }
        userFile.close();
    } else {
        std::cout << "No existing user file found. Creating a new user file." << std::endl;
    }

    // Create an admin object with default values
    Admin admin("John Doe", 5, 50000.0f, &marsLibrary);
    // Check if the admin file exists, if not, create a new admin
    std::ifstream adminFile("admin.txt");
    if (adminFile.is_open()) {
        admin.loadFromFile("admin.txt");
        adminFile.close();
    } else {
        std::cout << "No existing admin file found. Creating a new admin." << std::endl;
    }

    // Main loop for the program
    bool running = true;
    while (running) {
        std::cout << std::endl << title << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << menu << std::endl;

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

        switch (choice) {
        case 1: {
            // Add a new book to the library
            std::string title, genre, author;
            float size;
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);
            std::cout << "Enter book genre: ";
            std::getline(std::cin, genre);
            std::cout << "Enter book author: ";
            std::getline(std::cin, author);
            std::cout << "Enter book size (MB): ";
            std::cin >> size;
            std::cin.ignore();
            Book* newBook = new Book(title, genre, author, size);
            marsLibrary.addBook(newBook);
            std::cout << "Book added successfully!" << std::endl;
            break;
        }
        case 2: {
            // Remove a book from the library
            int bookID;
            std::cout << "Enter book ID to remove: ";
            std::cin >> bookID;
            std::cin.ignore();
            marsLibrary.removeBook(bookID);
            std::cout << "Book removed successfully!" << std::endl;
            break;
        }
        case 3: {
            // Add a new user to the library
            std::string name;
            float balance;
            int loyaltyYears;
            std::cout << "Enter user name: ";
            std::getline(std::cin, name);
            std::cout << "Enter user balance: ";
            std::cin >> balance;
            std::cin.ignore();
            std::cout << "Enter user loyalty years: ";
            std::cin >> loyaltyYears;
            std::cin.ignore();
            User* newUser = new User(name, balance, loyaltyYears);
            marsLibrary.addUser(newUser);
            users.push_back(newUser);
            std::cout << "User added successfully!" << std::endl;
            break;
        }
        case 4: {
            // Remove a user from the library
            int userID;
            std::cout << "Enter user ID to remove: ";
            std::cin >> userID;
            std::cin.ignore();
            marsLibrary.removeUser(userID);
            std::cout << "User removed successfully!" << std::endl;
            break;
        }
        case 5: {
            // Borrow a book from the library
            int userID, bookID;
            std::cout << "Enter user ID to borrow a book: ";
            std::cin >> userID;
            std::cout << "Enter book ID to borrow: ";
            std::cin >> bookID;
            std::cin.ignore();
            if (marsLibrary.borrowBook(userID, bookID)) {
                std::cout << "Book borrowed successfully!" << std::endl;
            } else {
                std::cout << "Failed to borrow the book." << std::endl;
            }
            break;
        }
        case 6: {
            // Return a book to the library
            int userID, bookID;
            std::cout << "Enter user ID to return a book: ";
            std::cin >> userID;
            std::cout << "Enter book ID to return: ";
            std::cin >> bookID;
            std::cin.ignore();
            if (marsLibrary.returnBook(userID, bookID)) {
                std::cout << "Book returned successfully!" << std::endl;
            } else {
                std::cout << "Failed to return the book." << std::endl;
            }
            break;
        }
        case 7: {
            // Reward a user
            int userID;
            std::cout << "Enter user ID to reward: ";
            std::cin >> userID;
            std::cin.ignore();
            for (User* user : users) {
                if (user->getID() == userID) {
                    admin.rewardUser(user);
                    break;
                }
            }
            break;
        }
        case 8: {
            // Reward the admin
            admin.rewardAdmin(&admin);
            break;
        }
		case 9: {
			// View all books in the library
			marsLibrary.printBooks(); 
			break;
		}
		case 10: {
			// View all users in the library
			marsLibrary.printUsers(); 
			break;
		}
		case 11: {
            // View transactions for a specific user
            int userID;
            std::cout << "Enter user ID to view transactions: ";
            std::cin >> userID;
            std::cin.ignore();
            TransactionReport::generateReport(marsLibrary.getTransactions(), marsLibrary.getBooks(), userID);
            break;
        }
        case 12:
            // Exit the program
            running = false;
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    // Save data to files
    marsLibrary.saveToFile("library.txt");

    // Save user data to files
    std::ofstream userOutputFile(userFilename);
    if (userOutputFile.is_open()) {
        userOutputFile << users.size() << std::endl;
        for (User* user : users) {
            user->saveToFile(userFilename + "." + std::to_string(user->getID()));
        }
        userOutputFile.close();
    }

    // Save admin data to file
    admin.saveToFile("admin.txt");

    // Clean up dynamically allocated memory
    for (User* user : users) {
        delete user;
    }

    return 0;
}
