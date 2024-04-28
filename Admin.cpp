#include "Admin.h"
#include <iostream>
#include <fstream>

Admin::Admin(const std::string& _name, int _yearsWithLibrary, float _salary, Library* _library)
    : id(generateAdminID()), name(_name), yearsWithLibrary(_yearsWithLibrary), salary(_salary), library(_library) {}

void Admin::setCurrentReward(const std::string& reward) 
{ 
	currentReward = reward; 
}

int Admin::getID() const {
    return id;
}

std::string Admin::getName() const {
    return name;
}

int Admin::getYearsWithLibrary() const {
    return yearsWithLibrary;
}

float Admin::getSalary() const {
    return salary;
}

void Admin::addWorker(User* user) {
    library->addUser(user);// Forward adding a user call to the Library class
}

void Admin::removeWorker(int userID) {
    library->removeUser(userID); // Forward removing a user call to the Library class
}

void Admin::rewardWorker(User* user, const std::string& reward) {
    // Implementation for rewarding user
    std::cout << "Rewarding user " << user->getName() << " with: " << reward << std::endl;
}

void Admin::rewardUser(User* user) {
	std::string reward;
	if (user->getLoyaltyYears() < 5) {
		reward = "Free book";
	} else if (user->getLoyaltyYears() < 10) {
		reward = "Extra checkout bandwidth";
	} else {
		reward = "Gift card";
	}

	user->setCurrentReward(reward);
	std::cout << "Rewarding user " << user->getName() << " with: " << reward << std::endl;
	user->addTransaction("Reward: " + reward); // Add a transaction for the reward
}

void Admin::rewardAdmin(Admin* admin) {
	std::string reward;
	if (admin->getYearsWithLibrary() < 3) {
		reward = "Salary increase";
	} else if (admin->getYearsWithLibrary() < 7) {
		reward = "Vacation time";
	} else {
		reward = "Promotion";
	}

	admin->setCurrentReward(reward);
	std::cout << "Rewarding admin " << admin->getName() << " with: " << reward << std::endl;
}


void Admin::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> id >> name >> yearsWithLibrary >> salary;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Admin::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << id << " " << name << " " << yearsWithLibrary << " " << salary;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
