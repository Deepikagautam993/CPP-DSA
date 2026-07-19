#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegative(vector<int>& arr, int k)
{
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < 0)
            dq.push_back(i);

        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        if(i >= k - 1)
        {
            if(dq.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};

    int k = 3;

    vector<int> ans = firstNegative(arr, k);

    for(int x : ans)
        cout << x << " ";

    return 0;
}
