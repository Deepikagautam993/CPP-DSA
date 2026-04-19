#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {5, -3, 5};

    int totalSum = 0;

    int currentMax = 0;
    int maxSum = nums[0];

    int currentMin = 0;
    int minSum = nums[0];

    for (int num : nums) {

        // Kadane for maximum subarray
        currentMax = max(num, currentMax + num);
        maxSum = max(maxSum, currentMax);

        // Kadane for minimum subarray
        currentMin = min(num, currentMin + num);
        minSum = min(minSum, currentMin);

        // total sum
        totalSum += num;
    }

    int result;

    // edge case: all numbers negative
    if (maxSum < 0) {
        result = maxSum;
    } 
    else {
        result = max(maxSum, totalSum - minSum);
    }

    cout << "Maximum Circular Subarray Sum: " << result;

    return 0;
}
