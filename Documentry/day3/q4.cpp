#include <iostream>
#include <vector>
using namespace std;

int findTheWinner(int n, int k) {
    vector<int> friends;
    for (int i = 1; i <= n; i++) {
        friends.push_back(i);
    }
    
    int index = 0;
    while (friends.size() > 1) {

        index = (index + k - 1) % friends.size();

        friends.erase(friends.begin() + index);
    }
    
    // Return the last remaining friend
    return friends[0];
}

int main() {
    int n = 5, k = 2;
    cout << "Winner: " << findTheWinner(n, k) << endl;
    return 0;
}
