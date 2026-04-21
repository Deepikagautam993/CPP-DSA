#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    
    unordered_map<int, int> mp;
    mp[0] = -1;

    int prefixSum = 0;
    int maxLength = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] == 0)
            prefixSum += -1;
        else
            prefixSum += 1;

        if(mp.count(prefixSum)) {
            maxLength = max(maxLength, i - mp[prefixSum]);
        }
        else {
            mp[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0,1,0,1};

    int ans = findMaxLength(nums);

    cout << "Longest Length: " << ans;

    return 0;
}
