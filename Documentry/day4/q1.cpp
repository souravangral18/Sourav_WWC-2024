#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Transaction {
    int id;
    double size;
    double frequency;
    std::string location;
    double suspiciousness;

    Transaction(int id, double size, double frequency, std::string location, double suspiciousness)
        : id(id), size(size), frequency(frequency), location(location), suspiciousness(suspiciousness) {}
};

bool compareBySuspiciousness(const Transaction& t1, const Transaction& t2) {
    return t1.suspiciousness > t2.suspiciousness;
}

int main() {
    // Sample dataset
    std::vector<Transaction> transactions = {
        Transaction(1, 500.0, 3.0, "New York", 85.5),
        Transaction(2, 1000.0, 1.0, "London", 92.3),
        Transaction(3, 200.0, 5.0, "Tokyo", 78.9),
        Transaction(4, 300.0, 4.0, "Delhi", 89.1)
    };

    // Sort transactions by suspiciousness score
    std::sort(transactions.begin(), transactions.end(), compareBySuspiciousness);

    // Flag high-risk transactions for review
    std::cout << "High-Risk Transactions:\n";
    for (const auto& transaction : transactions) {
        if (transaction.suspiciousness > 80.0) { // Threshold for high risk
            std::cout << "Transaction ID: " << transaction.id
                      << ", Suspiciousness: " << transaction.suspiciousness << "\n";
        }
    }

    return 0;
}
