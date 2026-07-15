#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s)
{
    stack<int> st;

    long long number = 0;
    char sign = '+';

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        // Build the current number
        if (isdigit(ch))
        {
            number = number * 10 + (ch - '0');
        }

        // Process the previous operator
        if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1)
        {
            if (sign == '+')
            {
                st.push(number);
            }
            else if (sign == '-')
            {
                st.push(-number);
            }
            else if (sign == '*')
            {
                int top = st.top();
                st.pop();
                st.push(top * number);
            }
            else if (sign == '/')
            {
                int top = st.top();
                st.pop();
                st.push(top / number);
            }

            sign = ch;
            number = 0;
        }
    }

    long long ans = 0;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return (int)ans;
}

int main()
{
    string s;

    cout << "Enter Expression : ";
    getline(cin, s);

    cout << "Answer : " << calculate(s);

    return 0;
}
