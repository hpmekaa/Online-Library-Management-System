#ifndef USER_H
#define USER_H

#include <string>
#include "IDGenerator.h"

// Class representing a user in the library
class User : public IDGenerator {
private:
    int id; // Unique ID for the user
    std::string name; // Name of the user
    float balance; // Balance in the user's account
    int loyaltyYears; // Number of years the user has been a member
    std::string accountStatus; // Status of the user's account
    std::vector<std::string> transactionHistory; // Transaction history of the user
	std::string currentReward; // Current reward of the user
	int maxBorrowedBooks; // Maximum number of books a user can borrow
    std::vector<int> borrowedBookIDs; // IDs of books borrowed by the user

public:
    // Constructor to initialize the User object
    User(const std::string& _name, float _balance, int _loyaltyYears);

    // Getters
    int getID() const; // Getter for user ID
    std::string getName() const; // Getter for user name
    float getBalance() const; // Getter for user balance
    int getLoyaltyYears() const; // Getter for user loyalty years
    std::string getAccountStatus() const; // Getter for user account status
    std::vector<std::string> getTransactionHistory() const; // Getter for user transaction history
    void setCurrentReward(const std::string& reward); // Setter for current user reward
    int getMaxBorrowedBooks() const; // Getter for maximum borrowed books
    std::vector<int> getBorrowedBookIDs() const; // Getter for borrowed book IDs

    // Setters
    void setAccountStatus(const std::string& _accountStatus); // Setter for account status
    void addTransaction(const std::string& transaction); // Method to add transaction to transaction history
    std::string getCurrentReward() const; // Getter for current user reward
	void setBorrowedBook(int bookID); // Method to set a borrowed book
    void returnBook(int bookID); // Method to return a borrowed book

	// Load and save methods
    void loadFromFile(const std::string& filename); // Method to load user details from a file
    void saveToFile(const std::string& filename); // Method to save user details to a file
	void setLastUserIdFromFile(int lastUserID); // Method to set the last user ID from a file
};

#endif // USER_H
