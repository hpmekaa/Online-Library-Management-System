#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "IDGenerator.h"

// Class representing a book in the library
class Book : public IDGenerator {
private:
    int id; // Unique ID for the book
    std::string title; // Title of the book
    std::string genre; // Genre of the book
    std::string author; // Author of the book
    bool available; // Availability status of the book
    float size_MB; // Size of the book in megabytes

public:
    // Constructor to initialize the Book object
    Book(const std::string& _title, const std::string& _genre, const std::string& _author, float _size_MB);

    // Getters
    int getID() const; // Getter for book ID
    std::string getTitle() const; // Getter for book title
    std::string getGenre() const; // Getter for book genre
    std::string getAuthor() const; // Getter for book author
    bool isAvailable() const; // Getter for book availability
    float getSize() const; // Getter for book size
	
    // Setters
    void setAvailable(bool _available); // Setter for book availability

	// Load and save methods
    void loadFromFile(const std::string& filename); // Method to load book details from a file
    void saveToFile(const std::string& filename); // Method to save book details to a file
	void setLastBookIdFromFile(int lastBookID); // Method to set the last book ID from a file
};

#endif // BOOK_H
