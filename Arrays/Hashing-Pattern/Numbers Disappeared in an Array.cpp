#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    
    unordered_set<int> s(nums.begin(), nums.end());
    vector<int> result;

    int n = nums.size();

    for(int i = 1; i <= n; i++) {
        if(s.count(i) == 0) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> ans = findDisappearedNumbers(nums);

    cout << "Missing Numbers: ";
    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
