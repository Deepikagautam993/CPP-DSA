#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    
    unordered_map<int, int> freq;

    for(int num : nums) {
        freq[num]++;
    }

    vector<vector<int>> bucket(nums.size() + 1);

    for(auto it : freq) {
        bucket[it.second].push_back(it.first);
    }

    vector<int> result;

    for(int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
        for(int num : bucket[i]) {
            result.push_back(num);
            if(result.size() == k) {
                return result;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";
    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
