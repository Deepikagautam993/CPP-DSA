#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for(char ch : s)
    {
        // Opening brackets
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // Stack should not be empty
            if(st.empty())
            {
                return false;
            }

            // Check matching brackets
            if((ch == ')' && st.top() == '(') ||
               (ch == '}' && st.top() == '{') ||
               (ch == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string s;

    cout << "Enter Bracket String : ";
    cin >> s;

    if(isValid(s))
    {
        cout << "Valid Parentheses";
    }
    else
    {
        cout << "Invalid Parentheses";
    }

    return 0;
}
