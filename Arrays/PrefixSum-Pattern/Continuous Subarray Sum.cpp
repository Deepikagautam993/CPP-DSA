#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    unordered_map<int,int> mp;

    mp[0] = -1;

    int prefixSum = 0;

    for(int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        int remainder = prefixSum % k;

        if(mp.find(remainder) != mp.end()) {

            if(i - mp[remainder] >= 2) {
                cout << "true";
                return 0;
            }

        } else {
            mp[remainder] = i;
        }
    }

    cout << "false";
}
