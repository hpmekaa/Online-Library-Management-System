#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

// Base class for ID generation
class IDGenerator {
protected:
  //  static int lastID;
	static int lastAdminID;
	static int lastBookID;
	static int lastUserID;
	static int lastTransactionID;
public:
  //  static int generateID();
    static int generateAdminID();
    static int generateBookID();
    static int generateUserID();
    static int generateTransactionID();
	static void setLastBookId(int lastBookID); 
	static void setLastUserId(int lastUserID); 
	static void setLastTransactionId(int lastTransactionID);

};

#endif // IDGENERATOR_H