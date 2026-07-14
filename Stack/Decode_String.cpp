#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<int> numberStack;
    stack<string> stringStack;

    int currentNumber = 0;
    string currentString = "";

    for(char ch : s)
    {
        if(isdigit(ch))
        {
            currentNumber = currentNumber * 10 + (ch - '0');
        }
        else if(ch == '[')
        {
            numberStack.push(currentNumber);
            stringStack.push(currentString);

            currentNumber = 0;
            currentString = "";
        }
        else if(ch == ']')
        {
            int repeat = numberStack.top();
            numberStack.pop();

            string previous = stringStack.top();
            stringStack.pop();

            string temp = "";

            for(int i = 0; i < repeat; i++)
            {
                temp += currentString;
            }

            currentString = previous + temp;
        }
        else
        {
            currentString += ch;
        }
    }

    return currentString;
}

int main()
{
    string s = "3[a2[c]]";

    cout << decodeString(s);

    return 0;
}
