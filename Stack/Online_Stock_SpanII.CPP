#include <iostream>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> &prices)
{
    int n = prices.size();

    vector<int> span(n);

    for(int i = 0; i < n; i++)
    {
        span[i] = 1;

        for(int j = i - 1; j >= 0; j--)
        {
            if(prices[j] <= prices[i])
            {
                span[i]++;
            }
            else
            {
                break;
            }
        }
    }

    return span;
}

int main()
{
    vector<int> prices = {100,80,60,70,60,75,85};

    vector<int> ans = stockSpan(prices);

    for(int x : ans)
    {
        cout << x << " ";
    }
}
