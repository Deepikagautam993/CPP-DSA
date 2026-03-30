#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        int leftSum = 0;
        int rightSum = 0;

        // left sum
        for(int j = 0; j < i; j++) {
            leftSum += nums[j];
        }

        // right sum
        for(int j = i + 1; j < n; j++) {
            rightSum += nums[j];
        }

        if(leftSum == rightSum) {
            return i;
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int result = pivotIndex(nums);

    cout << result;

}
