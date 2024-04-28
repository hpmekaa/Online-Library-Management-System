
#include "Book.h"
#include <iostream>
#include <fstream>


	Book::Book(const std::string& _title, const std::string& _genre, const std::string& _author, float _size_MB): id(generateBookID()), title(_title), genre(_genre), author(_author), available(true), size_MB(_size_MB) {}

	// Getters
	int Book::getID() const { return id; }
	std::string Book::getTitle() const { return title; }
	std::string Book::getGenre() const { return genre; }
	std::string Book::getAuthor() const { return author; }
	bool Book::isAvailable() const { return available; }
	float Book::getSize() const { return size_MB; }

	// Setters
	void Book::setAvailable(bool _available) { available = _available; }

	// Load and save methods
	void Book::loadFromFile(const std::string& filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			// Read data from file and set object attributes accordingly
			file >> id;
			std::getline(file, title);
			std::getline(file, genre);
			std::getline(file, author);
			file >> available >> size_MB;
			file.close();
		} else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}


	void Book::saveToFile(const std::string& filename) {
		std::ofstream file(filename);
		if (file.is_open()) {
			// Write object attributes to file
			file << id << " " << title << std::endl<< genre  << std::endl << author  << std::endl << available << " " << size_MB;
			file.close();
		} else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}

	void Book::setLastBookIdFromFile(int lastBookID){
	setLastBookId(lastBookID);
	}

