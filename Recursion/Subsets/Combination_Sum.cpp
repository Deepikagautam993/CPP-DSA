#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums,
           int index,
           int target,
           vector<int>& ds,
           vector<vector<int>>& ans) {

    // Base Case
    if(index == nums.size()) {

        if(target == 0) {
            ans.push_back(ds);
        }

        return;
    }

    // TAKE
    if(nums[index] <= target) {

        ds.push_back(nums[index]);

        // Stay on same index
        solve(nums,
              index,
              target - nums[index],
              ds,
              ans);

        // BACKTRACK
        ds.pop_back();
    }

    // SKIP
    solve(nums,
          index + 1,
          target,
          ds,
          ans);
}

int main() {

    vector<int> nums = {2,3,6,7};

    int target = 7;

    vector<int> ds;

    vector<vector<int>> ans;

    solve(nums,
          0,
          target,
          ds,
          ans);

    // Print answer
    for(auto vec : ans) {

        cout << "[ ";

        for(int val : vec)
            cout << val << " ";

        cout << "]" << endl;
    }

    return 0;
}
