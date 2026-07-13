#include <iostream>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int n = temperatures.size();

    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(temperatures[j] > temperatures[i])
            {
                ans[i] = j - i;
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemperatures(temperatures);

    cout << "Answer : ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
