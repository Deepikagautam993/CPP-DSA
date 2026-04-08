#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(nums[mid] > nums[high]){
                low = mid + 1;  // minimum in right half
            }
            else{
                high = mid;     // minimum in left half including mid
            }
        }

        return nums[low]; // minimum element
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << endl; 
}
