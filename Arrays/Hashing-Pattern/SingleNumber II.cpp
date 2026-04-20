#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;

    for(int num : nums) {
        freq[num]++;
    }

    for(auto it : freq) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};

    cout << "Single Number II: " << singleNumber(nums);

    return 0;
}
