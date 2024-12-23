#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base cases: when the range has only one number
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Fill the DP table for ranges of increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }

        // Player 1 wins if the score difference is non-negative
        return dp[0][n-1] >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 2};
    cout << (solution.PredictTheWinner(nums) ? "Player 1 can win" : "Player 1 cannot win") << endl;

    return 0;
}
