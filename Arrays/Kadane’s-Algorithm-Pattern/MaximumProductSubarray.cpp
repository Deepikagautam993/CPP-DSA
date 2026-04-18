#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> nums = {2, 3, -2, 4};

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        // If negative number, swap
        if(nums[i] < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = max(result, maxProd);
    }

    cout << "Maximum Product Subarray = " << result;

    return 0;
}
