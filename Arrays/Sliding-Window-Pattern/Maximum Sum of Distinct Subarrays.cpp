#include <iostream>
#include <vector>
using namespace std;

bool isDistinct(vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k; i++) {
        for (int j = i + 1; j < start + k; j++) {
            if (nums[i] == nums[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    int n = nums.size();
    int maxSum = 0;

    for (int i = 0; i <= n - k; i++) {

        if (isDistinct(nums, i, k)) {

            int sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    cout << "Maximum Sum: " << maxSum;
}
