#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n = nums.size();

    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        // Search next n-1 elements (Circular)
        for(int j = 1; j < n; j++)
        {
            int nextIndex = (i + j) % n;

            if(nums[nextIndex] > nums[i])
            {
                ans[i] = nums[nextIndex];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,1};

    vector<int> ans = nextGreaterElements(nums);

    cout << "Answer : ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
