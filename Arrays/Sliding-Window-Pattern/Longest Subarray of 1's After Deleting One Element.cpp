#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 0, 1};

    int left = 0;
    int zeroes = 0;
    int maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {

        // count zero
        if (nums[right] == 0) {
            zeroes++;
        }

        // shrink window if more than one zero
        while (zeroes > 1) {
            if (nums[left] == 0) {
                zeroes--;
            }
            left++;
        }

        // update maximum length
        maxLen = max(maxLen, right - left);
    }

    cout << "Longest subarray length: " << maxLen;

    return 0;
}
