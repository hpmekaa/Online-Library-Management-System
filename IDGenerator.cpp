#include "IDGenerator.h"

// Initialize the static member variable
//int IDGenerator::lastID = 0;
int IDGenerator::lastAdminID = 0;
int IDGenerator::lastBookID = 0;
int IDGenerator::lastUserID = 0;
int IDGenerator::lastTransactionID = 0;


// Base class for Admin ID generation
int IDGenerator::generateAdminID() {
    return ++lastAdminID;
}


void IDGenerator::setLastBookId(int lastBookID) { IDGenerator::lastBookID = lastBookID; }

void IDGenerator::setLastUserId(int lastUserID) { IDGenerator::lastUserID = lastUserID; }

void IDGenerator::setLastTransactionId(int lastTransactionID) { IDGenerator::lastTransactionID = lastTransactionID; }

// Base class for Book ID generation
int IDGenerator::generateBookID() {
    return ++lastBookID;
}

// Base class for User ID generation
int IDGenerator::generateUserID() {
    return ++lastUserID;
}

// Base class for Transaction ID generation
int IDGenerator::generateTransactionID() {
    return ++lastTransactionID;
}
