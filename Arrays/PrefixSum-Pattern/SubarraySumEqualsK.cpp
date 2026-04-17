#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    unordered_map<int,int> mp;

    mp[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for(int num : nums) {

        prefixSum += num;

        if(mp.find(prefixSum - k) != mp.end()) {
            count += mp[prefixSum - k];
        }

        mp[prefixSum]++;
    }

    cout << "Total subarrays = " << count;

    return 0;
}
