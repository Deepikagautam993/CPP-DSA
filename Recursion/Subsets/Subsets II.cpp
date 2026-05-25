#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& nums,
           int index,
           vector<int>& ds,
           vector<vector<int>>& ans) {

    // Store current subset
    ans.push_back(ds);

    // Loop
    for(int i = index;
        i < nums.size();
        i++) {

        // Skip duplicates
        if(i > index &&
           nums[i] == nums[i - 1]) {

            continue;
        }

        // TAKE
        ds.push_back(nums[i]);

        // Recursive Call
        solve(nums,
              i + 1,
              ds,
              ans);

        // BACKTRACK
        ds.pop_back();
    }
}

int main() {

    vector<int> nums = {1,2,2};

    // Sort array
    sort(nums.begin(),
         nums.end());

    vector<int> ds;

    vector<vector<int>> ans;

    solve(nums,
          0,
          ds,
          ans);

    // Print answer
    for(auto subset : ans) {

        cout << "[ ";

        for(int val : subset)
            cout << val << " ";

        cout << "]" << endl;
    }

    return 0;
}
