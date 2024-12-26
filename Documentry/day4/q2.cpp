#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

struct Trade {
    std::string timestamp;
    std::string stockSymbol;
    double tradePrice;
    int tradeVolume;

    Trade(std::string ts, std::string sym, double price, int volume)
        : timestamp(ts), stockSymbol(sym), tradePrice(price), tradeVolume(volume) {}
};

bool compareByTimestampAndSymbol(const Trade& t1, const Trade& t2) {
    if (t1.timestamp == t2.timestamp) {
        return t1.stockSymbol < t2.stockSymbol;
    }
    return t1.timestamp < t2.timestamp;
}

void groupByVolumeTrends(const std::vector<Trade>& trades) {
    std::map<std::string, std::vector<Trade>> volumeGroups;

    for (const auto& trade : trades) {
        std::string volumeCategory;
        if (trade.tradeVolume < 1000) {
            volumeCategory = "Low Volume";
        } else if (trade.tradeVolume < 10000) {
            volumeCategory = "Medium Volume";
        } else {
            volumeCategory = "High Volume";
        }
        volumeGroups[volumeCategory].push_back(trade);
    }

    // Display grouped data
    for (const auto& group : volumeGroups) {
        std::cout << group.first << ":\n";
        for (const auto& trade : group.second) {
            std::cout << "  " << trade.timestamp << ", " << trade.stockSymbol
                      << ", Price: " << trade.tradePrice
                      << ", Volume: " << trade.tradeVolume << "\n";
        }
    }
}

int main() {
    // Sample dataset
    std::vector<Trade> trades = {
        Trade("2024-12-24T10:00:00Z", "AAPL", 175.5, 500),
        Trade("2024-12-24T10:00:01Z", "GOOG", 2845.0, 1500),
        Trade("2024-12-24T10:00:02Z", "AAPL", 176.0, 700),
        Trade("2024-12-24T10:00:01Z", "MSFT", 310.0, 11000),
        Trade("2024-12-24T10:00:03Z", "TSLA", 725.0, 8500)
    };

    // Sort trades by timestamp and stock symbol
    std::sort(trades.begin(), trades.end(), compareByTimestampAndSymbol);

    // Display sorted trades
    std::cout << "Sorted Trades:\n";
    for (const auto& trade : trades) {
        std::cout << trade.timestamp << ", " << trade.stockSymbol
                  << ", Price: " << trade.tradePrice
                  << ", Volume: " << trade.tradeVolume << "\n";
    }
    std::cout << "\nGrouped by Volume Trends:\n";
    groupByVolumeTrends(trades);

    return 0;
}
