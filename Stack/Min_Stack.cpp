#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> st;
    stack<int> minSt;

public:

    void push(int val)
    {
        st.push(val);

        if(minSt.empty())
        {
            minSt.push(val);
        }
        else
        {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop()
    {
        if(st.empty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        st.pop();
        minSt.pop();
    }

    int top()
    {
        if(st.empty())
        {
            return -1;
        }

        return st.top();
    }

    int getMin()
    {
        if(minSt.empty())
        {
            return -1;
        }

        return minSt.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Minimum : " << ms.getMin() << endl;

    ms.pop();

    cout << "Top : " << ms.top() << endl;
    cout << "Minimum : " << ms.getMin() << endl;

    return 0;
}
