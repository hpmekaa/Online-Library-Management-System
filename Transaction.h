#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include "IDGenerator.h"

// Class representing a transaction in the library
class Transaction : public IDGenerator {
private:
    int id; // Unique ID for the transaction
    std::time_t timestamp; // Timestamp of the transaction
    std::string type; // Type of transaction (borrow, renew, return)
    std::vector<int> bookIDs; // IDs of books involved in the transaction
    int userID; // ID of the user involved in the transaction

public:
    // Constructor to initialize the Transaction object
    Transaction(const std::string& _type, const std::vector<int>& _bookIDs, int _userID);

    // Getters
    int getID() const; // Getter for transaction ID
    std::time_t getTimestamp() const; // Getter for transaction timestamp
    std::string getType() const; // Getter for transaction type
    std::vector<int> getBookIDs() const; // Getter for book IDs involved in the transaction
    int getUserID() const; // Getter for user ID involved in the transaction
	
	// Load and save methods
    void loadFromFile(const std::string& filename); // Method to load transaction details from a file
    void saveToFile(const std::string& filename); // Method to save transaction details to a file
	void setLastTransactionIdFromFile(int lastTransactionID); // Method to set the last transaction ID from a file
};

#endif // TRANSACTION_H
