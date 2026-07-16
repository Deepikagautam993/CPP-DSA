#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> q1, q2;

public:

    bool isEmpty()
    {
        return q1.empty();
    }

    // Push (Costly)
    void push(int value)
    {
        // New element ko q2 me dalo
        q2.push(value);

        // q1 ke saare elements q2 me transfer karo
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 aur q2
        swap(q1, q2);

        cout << value << " pushed into Stack." << endl;
    }

    // Pop
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << q1.front() << " popped from Stack." << endl;
        q1.pop();
    }

    // Top
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return q1.front();
    }

    // Display
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        queue<int> temp = q1;

        cout << "Stack (Top -> Bottom): ";

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top : " << st.top() << endl;

    st.pop();

    st.display();

    st.push(40);

    st.display();

    return 0;
}
