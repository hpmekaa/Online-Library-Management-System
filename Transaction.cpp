#include "Transaction.h"
#include <iostream>
#include <fstream>

Transaction::Transaction(const std::string& _type, const std::vector<int>& _bookIDs, int _userID)
    : id(generateTransactionID()), timestamp(std::time(nullptr)), type(_type), bookIDs(_bookIDs), userID(_userID) {}

// Getters
int Transaction::getID() const { return id; }
std::time_t Transaction::getTimestamp() const { return timestamp; }
std::string Transaction::getType() const { return type; }
std::vector<int> Transaction::getBookIDs() const { return bookIDs; }
int Transaction::getUserID() const { return userID; }

// Load and save methods
void Transaction::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        // Read data from file and set object attributes accordingly
        file >> id >> timestamp >> type >> userID;
        int bookID;
        while (file >> bookID) {
            bookIDs.push_back(bookID);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Transaction::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Write object attributes to file
        file << id << " " << timestamp << " " << type << " " << userID << std::endl;
        for (const auto& bookID : bookIDs) {
            file << bookID << " ";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Transaction::setLastTransactionIdFromFile(int lastTransactionID){
    setLastTransactionId(lastTransactionID);
}
