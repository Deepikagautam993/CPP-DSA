#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> last(26);
    vector<bool> visited(26, false);

    // Store last occurrence of each character
    for(int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }

    stack<char> st;

    // Traverse the string
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        // Skip duplicate characters
        if(visited[ch - 'a'])
        {
            continue;
        }

        // Remove larger characters if they appear again later
        while(!st.empty() &&
              st.top() > ch &&
              last[st.top() - 'a'] > i)
        {
            visited[st.top() - 'a'] = false;
            st.pop();
        }

        // Push current character
        st.push(ch);
        visited[ch - 'a'] = true;
    }

    // Build answer from stack
    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Stack gives reverse order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "cbacdcbc";

    cout << "Answer : " << removeDuplicateLetters(s);

    return 0;
}
