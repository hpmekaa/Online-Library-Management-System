#include "Library.h"
#include <iostream>
#include <fstream>
#include <algorithm>

    Library::Library(const std::string& _name) : name(_name), totalBooks(0), totalBandwidth(0.0f) {}

    // Getters
    std::string Library::getName() const { return name; }
    int Library::getTotalBooks() const { return totalBooks; }
    float Library::getTotalBandwidth() const { return totalBandwidth; }
    std::vector<Book*> Library::getBooks() const { return books; }
    std::vector<User*> Library::getUsers() const { return users; }
    std::vector<Transaction*> Library::getTransactions() const { return transactions; }

    // Methods
    void Library::addBook(Book* book) {
        books.push_back(book);
        totalBooks++;
    }

    void Library::addUser(User* user) {
        users.push_back(user);
    }

    void Library::removeBook(int bookID) {
        auto it = std::find_if(books.begin(), books.end(),
            [bookID](const Book* book) { return book->getID() == bookID; });
        if (it != books.end()) {
            delete *it;
            books.erase(it);
            totalBooks--;
        }
    }

    void Library::removeUser(int userID) {
        auto it = std::find_if(users.begin(), users.end(),
            [userID](const User* user) { return user->getID() == userID; });
        if (it != users.end()) {
            delete *it;
            users.erase(it);
        }
    }
    void Library::loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            // Read data from file and set object attributes accordingly
            file >> name >> totalBooks >> totalBandwidth;

            int numBooks;
            file >> numBooks;
            file.ignore(); // Ignore newline character
            for (int i = 0; i < numBooks; i++) {
                Book* book = new Book("", "", "", 0.0f);
                book->loadFromFile("book." + std::to_string(i + 1));
				book->setLastBookIdFromFile(i+1);
                books.push_back(book);
            }
			
            int numUsers;
            file >> numUsers;
            file.ignore(); // Ignore newline character
          for (int i = 0; i < numUsers; i++) {
                User* user = new User("", 0.0f, 0);
                user->loadFromFile("user." + std::to_string(i + 1));
				user->setLastUserIdFromFile(i+1);
                users.push_back(user);
            }

            int numTransactions;
            file >> numTransactions;
            file.ignore(); // Ignore newline character


            for (int i = 0; i < numTransactions; i++) {
                Transaction* transaction = new Transaction("", std::vector<int>(), 0);
                transaction->loadFromFile("transaction." + std::to_string(i + 1));
				transaction->setLastTransactionIdFromFile(i+1);
                transactions.push_back(transaction);
            }

            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void Library::saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            // Write object attributes to file
            file << name << " " << totalBooks << " " << totalBandwidth << std::endl;
            file << books.size() << std::endl;
            for (const auto& book : books) {
                book->saveToFile("book." + std::to_string(book->getID()));
            }
            file << users.size() << std::endl;
            for (const auto& user : users) {
                user->saveToFile("user." + std::to_string(user->getID()));
            }
            file << transactions.size() << std::endl;
            for (const auto& transaction : transactions) {
                transaction->saveToFile("transaction." + std::to_string(transaction->getID()));
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
    bool Library::borrowBook(int userID, int bookID) {
	// Find the user and book, handle potential null pointers
	// Check if the user can borrow the book (availability and borrow limit)
	// If successful, update book availability, user borrowed books, and create a transaction
  
        User* user = nullptr;
        Book* book = nullptr;

        // Find the user and book
        for (User* u : users) {
            if (u->getID() == userID) {
                user = u;
                break;
            }
        }
        for (Book* b : books) {
            if (b->getID() == bookID) {
                book = b;
                break;
            }
        }
		if (!user){
			 std::cout << "No existing user found for the userid provided." << std::endl;
		} 
    	if (!book){
			 std::cout << "No existing book found for the bookid provided." << std::endl;
			
		} 

        // Check if the user can borrow the book
        if (user && book && book->isAvailable() && user->getBorrowedBookIDs().size() < user->getMaxBorrowedBooks()) {
            book->setAvailable(false);
            user->setBorrowedBook(bookID);
            transactions.emplace_back(new Transaction("Borrow", { bookID }, userID));
            return true;
        }

        return false;
    }


    bool Library::returnBook(int userID, int bookID) {
        User* user = nullptr;
        Book* book = nullptr;

        // Find the user and book
        for (User* u : users) {
            if (u->getID() == userID) {
                user = u;
                break;
            }
        }
        for (Book* b : books) {
            if (b->getID() == bookID) {
                book = b;
                break;
            }
        }

		if (!user){
			 std::cout << "No existing user found for the userid provided." << std::endl;
		} 
    	if (!book){
			 std::cout << "No existing book found for the bookid provided." << std::endl;
			
		} 

        // Check if the user has borrowed the book
        if (user && book && !book->isAvailable()) {
            book->setAvailable(true);
            user->returnBook(bookID);
            transactions.emplace_back(new Transaction("Return", { bookID }, userID));
            return true;
        }
        return false;
    }

	void Library::printBooks() const {
		// Check if there are any books
		if (books.empty()) {
			std::cout << "No books in Library." << std::endl;
		} else {
		// Print information about each book	
			std::cout << "Books in the library:" << std::endl;
			for (const auto& book : books) {
				std::cout << "Book ID: " << book->getID() << ", Title: " << book->getTitle()<< book->isAvailable()<< std::endl;
			}
		}
	}

	void Library::printUsers() const {
		// Check if there are any users
		if (users.empty()) {
			std::cout << "No users with Library." << std::endl;
		} else {
			// Print information about each user
			std::cout << "Users in the library:" << std::endl;
			for (const auto& user : users) {
				std::cout << "User ID: " << user->getID() << ", Name: " << user->getName() << std::endl;
			}
		}
	}
