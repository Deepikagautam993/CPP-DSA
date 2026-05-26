#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums,
           vector<int>& ds,
           vector<vector<int>>& ans,
           vector<bool>& visited) {

    // Base Case
    if(ds.size() == nums.size()) {

        ans.push_back(ds);
        return;
    }

    // Try every element
    for(int i = 0;
        i < nums.size();
        i++) {

        // Already used
        if(visited[i] == true)
            continue;

        // TAKE
        visited[i] = true;

        ds.push_back(nums[i]);

        solve(nums,
              ds,
              ans,
              visited);

        // BACKTRACK
        ds.pop_back();

        visited[i] = false;
    }
}

int main() {

    vector<int> nums = {1,2,3};

    vector<int> ds;

    vector<vector<int>> ans;

    vector<bool> visited(nums.size(),
                         false);

    solve(nums,
          ds,
          ans,
          visited);

    // Print answer
    for(auto vec : ans) {

        cout << "[ ";

        for(int val : vec)
            cout << val << " ";

        cout << "]" << endl;
    }

    return 0;
}
