#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Struct representing a catalog item
struct CatalogItem {
    std::string title;       
    int totalViews;         
    double averageRating;   
    int releaseYear;        
    double popularityScore; 
    double relevanceScore;

    CatalogItem(std::string t, int views, double rating, int year)
        : title(t), totalViews(views), averageRating(rating), releaseYear(year),
          popularityScore(0), relevanceScore(0) {}
};

// Function to calculate popularity score
void calculatePopularityScores(std::vector<CatalogItem>& catalog) {
    for (auto& item : catalog) {
        item.popularityScore = (item.totalViews * 0.7) +
                               (item.averageRating * 100 * 0.2) +
                               ((2024 - item.releaseYear) * 0.1);
    }
}

bool compareByPopularity(const CatalogItem& a, const CatalogItem& b) {
    return a.popularityScore > b.popularityScore;
}

void calculateRelevanceScores(std::vector<CatalogItem>& catalog, const std::vector<std::string>& userHistory) {
    for (auto& item : catalog) {
        // Example formula: Relevance = matches in history * weight
        int matches = std::count(userHistory.begin(), userHistory.end(), item.title);
        item.relevanceScore = matches * 100; // Assign higher weight to matched items
    }
}

bool compareByRelevance(const CatalogItem& a, const CatalogItem& b) {
    return a.relevanceScore > b.relevanceScore;
}



int main() {
    // Sample catalog
    std::vector<CatalogItem> catalog = {
        CatalogItem("Movie A", 500000, 4.5, 2022),
        CatalogItem("Show B", 1000000, 4.7, 2021),
        CatalogItem("Movie C", 250000, 4.2, 2020),
        CatalogItem("Show D", 750000, 4.8, 2023)
    };

    std::vector<std::string> userHistory = {"Movie A", "Show B", "Movie A"};

    calculatePopularityScores(catalog);
    std::sort(catalog.begin(), catalog.end(), compareByPopularity);

    std::cout << "Trending Content (By Popularity):\n";
    for (const auto& item : catalog) {
        std::cout << item.title << ", Popularity Score: " << item.popularityScore << "\n";
    }

    calculateRelevanceScores(catalog, userHistory);
    std::sort(catalog.begin(), catalog.end(), compareByRelevance);

    std::cout << "\nPersonalized Recommendations (By Relevance):\n";
    for (const auto& item : catalog) {
        std::cout << item.title << ", Relevance Score: " << item.relevanceScore << "\n";
    }

    return 0;
}
