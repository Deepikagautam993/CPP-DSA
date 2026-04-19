#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<int> nums = {1, -3, 2, 3, -4};

    int currentMax = 0;
    int maxSum = 0;

    int currentMin = 0;
    int minSum = 0;

    for (int num : nums) {

        currentMax = max(num, currentMax + num);
        maxSum = max(maxSum, currentMax);

        currentMin = min(num, currentMin + num);
        minSum = min(minSum, currentMin);
    }

    int result = max(abs(maxSum), abs(minSum));

    cout << "Maximum Absolute Subarray Sum: " << result;

    return 0;
}
