#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;

    for(char digit : num)
    {
        while(!st.empty() &&
              k > 0 &&
              st.top() > digit)
        {
            st.pop();
            k--;
        }

        st.push(digit);
    }

    while(k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;

    while(i < ans.size() && ans[i] == '0')
    {
        i++;
    }

    ans = ans.substr(i);

    if(ans.empty())
    {
        return "0";
    }

    return ans;
}

int main()
{
    string num = "1432219";
    int k = 3;

    cout << removeKdigits(num, k);

    return 0;
}
