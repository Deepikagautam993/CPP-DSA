#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1, last = -1;

        // Find first occurrence
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                first = mid;         // possible first occurrence
                high = mid - 1;      // move left
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Reset pointers to find last occurrence
        low = 0;
        high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                last = mid;          // possible last occurrence
                low = mid + 1;       // move right
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {first, last};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
}
