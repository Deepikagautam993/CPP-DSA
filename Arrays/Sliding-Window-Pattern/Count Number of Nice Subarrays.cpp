#include <iostream>
#include <vector>
using namespace std;

// function to count subarrays with at most k odd numbers
int atMost(vector<int>& nums, int k) {
    int left = 0;
    int count = 0;
    int odd = 0;

    for (int right = 0; right < nums.size(); right++) {

        if (nums[right] % 2 == 1) {
            odd++;
        }

        while (odd > k) {
            if (nums[left] % 2 == 1) {
                odd--;
            }
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = atMost(nums, k) - atMost(nums, k - 1);

    cout << "Number of nice subarrays: " << result;

    return 0;
}
