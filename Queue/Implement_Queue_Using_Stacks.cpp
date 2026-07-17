#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();

        return ans;
    }

    int peek()
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front : " << q.peek() << endl;

    cout << "Deleted : " << q.pop() << endl;
    cout << "Deleted : " << q.pop() << endl;

    q.push(40);

    cout << "Front : " << q.peek() << endl;

    while(!q.empty())
    {
        cout << q.pop() << " ";
    }

    return 0;
}
