#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans;

    // Traverse every element of nums1
    for(int i = 0; i < nums1.size(); i++)
    {
        int current = nums1[i];
        bool found = false;
        int nextGreater = -1;

        // Find current element in nums2
        for(int j = 0; j < nums2.size(); j++)
        {
            if(nums2[j] == current)
            {
                found = true;
            }

            // Once current element is found,
            // search for first greater element
            if(found && nums2[j] > current)
            {
                nextGreater = nums2[j];
                break;
            }
        }

        ans.push_back(nextGreater);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    cout << "Answer : ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
