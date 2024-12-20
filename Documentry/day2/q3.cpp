#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[uniqueIndex]) {
            ++uniqueIndex;
            nums[uniqueIndex] = nums[i];
        }
    }
    return uniqueIndex + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5};
    int uniqueCount = removeDuplicates(nums);
    
    cout << "Unique elements count: " << uniqueCount << endl;
    cout << "Modified array: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}
