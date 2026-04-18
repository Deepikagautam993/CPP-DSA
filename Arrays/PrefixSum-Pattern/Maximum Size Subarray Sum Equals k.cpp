#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;

    unordered_map<int,int> mp;

    mp[0] = -1;

    int prefixSum = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        if(mp.find(prefixSum - k) != mp.end()) {

            int len = i - mp[prefixSum - k];

            if(len > maxLen) {
                maxLen = len;
            }
        }

        if(mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    cout << "Maximum Length = " << maxLen;

    return 0;
}
