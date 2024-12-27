#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool searchInSorted(vector<int> arr, int k) {

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // To avoid overflow

            if (arr[mid] == k) {
                return true; // k is found
            } else if (arr[mid] < k) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return false;     }
};
