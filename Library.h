#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector> // Include vector for storing collections of books and users
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class Library {
private:
  std::string name;
  int totalBooks;
  float totalBandwidth;
  std::vector<Book*> books; // Vector to store pointers to Book objects
  std::vector<User*> users;  // Vector to store pointers to User objects
  std::vector<Transaction*> transactions; // Vector to store pointers to Transaction objects

public:
  Library(const std::string& _name);

  // Getters
  std::string getName() const;
  int getTotalBooks() const;
  float getTotalBandwidth() const;
  std::vector<Book*> getBooks() const; // Returns a copy of the books vector
  std::vector<User*> getUsers() const; // Returns a copy of the users vector
  std::vector<Transaction*> getTransactions() const; // Returns a copy of the transactions vector

  // Methods
  void addBook(Book* book);
  void addUser(User* user);
  void removeBook(int bookID);
  void removeUser(int userID);
  void loadFromFile(const std::string& filename);
  void saveToFile(const std::string& filename);
  bool borrowBook(int userID, int bookID); // Method to borrow a book
  bool returnBook(int userID, int bookID); // Method to return a book
  void printBooks() const; // Method to print information about all books
  void printUsers() const; // Method to print information about all users
};

#endif // LIBRARY_H