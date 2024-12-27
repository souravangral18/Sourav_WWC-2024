#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        
        vector<int> initialIndices(m, 0);
        int initialSum = 0;
        for (int i = 0; i < m; ++i) {
            initialSum += mat[i][0];
        }
        minHeap.push({initialSum, initialIndices});
        
        set<vector<int>> visited;
        visited.insert(initialIndices);
        
        for (int i = 0; i < k; ++i) {
            auto [currentSum, indices] = minHeap.top();
            minHeap.pop();
            
            if (i == k - 1) {
                return currentSum;
            }
            
            for (int j = 0; j < m; ++j) {
                if (indices[j] + 1 < n) { // Check if we can increment the index
                    vector<int> newIndices = indices;
                    newIndices[j]++; // Increment the index for row j
                    int newSum = currentSum - mat[j][indices[j]] + mat[j][newIndices[j]]; // Update the sum
                    
                    if (visited.find(newIndices) == visited.end()) {
                        visited.insert(newIndices);
                        minHeap.push({newSum, newIndices});
                    }
                }
            }
        }
        
        return -1; 
    }
};