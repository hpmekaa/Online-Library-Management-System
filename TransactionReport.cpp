// TransactionReport.cpp
#include "TransactionReport.h"
#include <iostream>

void TransactionReport::generateReport(const std::vector<Transaction*>& transactions, const std::vector<Book*>& books, int userID) {
    int totalBooksRead = 0;
    float totalBandwidthUsed = 0.0f;

    std::cout << "Transaction Report for User ID: " << userID << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (const auto& transaction : transactions) {
        if (transaction->getUserID() == userID) {
            std::cout << "Transaction ID: " << transaction->getID() << std::endl;
            std::cout << "Timestamp: " << transaction->getTimestamp() << std::endl;
            std::cout << "Type: " << transaction->getType() << std::endl;
            std::cout << "Book IDs: ";
            for (const auto& bookID : transaction->getBookIDs()) {
                std::cout << bookID << " ";
                if (transaction->getType() == "Borrow") {
                    totalBooksRead++;
                }

                // Find the corresponding book and add its size to the total bandwidth
                for (const auto& book : books) {
                    if (book->getID() == bookID) {
                        totalBandwidthUsed += book->getSize();
                        break;
                    }
                }
            }
            std::cout << std::endl;

            std::cout << "------------------------------------" << std::endl;
        }
    }

    std::cout << "Total Books Read: " << totalBooksRead << std::endl;
    std::cout << "Total Bandwidth Used: " << totalBandwidthUsed << " MB" << std::endl;
}
