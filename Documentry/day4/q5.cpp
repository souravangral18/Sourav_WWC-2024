#include <iostream>
#include <vector>

struct Ad {
    std::string advertiserName;
    double bidAmount;
    double engagementRate;
    double remainingBudget;
};

double calculateAdScore(const Ad& ad) {
    return ad.bidAmount * 0.5 + ad.engagementRate * 0.3 + ad.remainingBudget * 0.2;
}

// Selection Sort function to sort ads by score
void selectionSort(std::vector<Ad>& ads) {
    int n = ads.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;  // Assume the current index has the highest score
        for (int j = i + 1; j < n; j++) {
            // Compare ad scores and update maxIdx if a higher score is found
            if (calculateAdScore(ads[j]) > calculateAdScore(ads[maxIdx])) {
                maxIdx = j;
            }
        }
        // Swap the current element with the element having the maximum score
        if (maxIdx != i) {
            std::swap(ads[i], ads[maxIdx]);
        }
    }
}

int main() {
    // Sample list of ads
    std::vector<Ad> ads = {
        {"Advertiser A", 1000.0, 0.8, 5000.0},
        {"Advertiser B", 1500.0, 0.7, 2000.0},
        {"Advertiser C", 1200.0, 0.9, 3000.0},
        {"Advertiser D", 800.0, 0.75, 4000.0},
        {"Advertiser E", 2000.0, 0.85, 6000.0}
    };

    // Sort ads using Selection Sort
    selectionSort(ads);

    // Display sorted ads
    std::cout << "Ad Scheduling (Sorted by Priority):\n";
    for (const auto& ad : ads) {
        std::cout << "Advertiser: " << ad.advertiserName 
                  << ", Bid: " << ad.bidAmount 
                  << ", Engagement Rate: " << ad.engagementRate 
                  << ", Remaining Budget: " << ad.remainingBudget << "\n";
    }

    return 0;
}