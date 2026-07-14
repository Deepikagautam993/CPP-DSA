#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> st;

    for(string token : tokens)
    {
        if(token == "+" || token == "-" ||
           token == "*" || token == "/")
        {
            int num2 = st.top();
            st.pop();

            int num1 = st.top();
            st.pop();

            if(token == "+")
                st.push(num1 + num2);

            else if(token == "-")
                st.push(num1 - num2);

            else if(token == "*")
                st.push(num1 * num2);

            else
                st.push(num1 / num2);
        }
        else
        {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main()
{
    vector<string> tokens = {"2","1","+","3","*"};

    cout << evalRPN(tokens);

    return 0;
}
