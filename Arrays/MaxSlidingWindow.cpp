#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> result;

    for(int i = 0; i <= n - k; i++) {

        int maxVal = nums[i];

        for(int j = i; j < i + k; j++) {
            if(nums[j] > maxVal)
                maxVal = nums[j];
        }

        result.push_back(maxVal);
    }

    return result;
}

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int x : ans)
        cout << x << " ";
}
