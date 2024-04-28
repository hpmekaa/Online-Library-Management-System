#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Library.h" 
#include "User.h" 
#include "IDGenerator.h" 

class Admin : public IDGenerator {
private:
  int id;
  std::string name;
  int yearsWithLibrary;
  float salary;
  Library* library; // Pointer to the Library object
  std::string currentReward;

public:
  Admin(const std::string& _name, int _yearsWithLibrary, float _salary, Library* _library);
  
  // Setters
  void setCurrentReward(const std::string& reward);
  
  // Getters
  int getID() const;
  std::string getName() const;
  int getYearsWithLibrary() const;
  float getSalary() const;
  std::string getCurrentReward() const;
  
  // Methods
  void addWorker(User* user); // Method to add a new worker (user) to the library
  void removeWorker(int userID); // Method to remove a worker (user) from the library
  void rewardUser(User* user); // Method to reward a user
  void rewardAdmin(Admin* admin); // Method to reward another admin
  void rewardWorker(User* user, const std::string& reward); // Method to reward a worker with a custom reward
  void loadFromFile(const std::string& filename);
  void saveToFile(const std::string& filename);
};

#endif // ADMIN_H