#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

   int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;  // Less than 2 elements ? max gap is 0

        sort(nums.begin(), nums.end());  // Step 1: sort array

        int maxGap = 0;
        for (int i = 1; i < n; i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);  // Step 2: find gap between consecutive elements
        }

        return maxGap;
    }

int main() {
    Solution sol;
    vector<int> nums = {3, 6, 9, 1};

    int result = sol.maximumGap(nums);
    cout << "Maximum Gap: " << result << endl; // Output: 3

    return 0;
}
