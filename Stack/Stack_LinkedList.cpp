#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};


class Stack
{
public:
    Node* top;

    // Constructor
    Stack()
    {
        top = NULL;
    }

    
    void push(int data)
    {
        Node* newNode = new Node(data);

        newNode->next = top;

        top = newNode;
    }

    
    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;

        top = top->next;

        delete temp;
    }

    
    int peek()
    {
        if(top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return top->data;
    }

    
    bool isEmpty()
    {
        return top == NULL;
    }

    // Display (Extra Utility Function)
    void display()
    {
        if(top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        Node* temp = top;

        while(temp != NULL)
        {
            cout << temp->data << " ";

            temp = temp->next;
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
    st.push(40);

    cout << "Stack : ";
    st.display();

    cout << "Top Element : " << st.peek() << endl;

    st.pop();

    cout << "After Pop : ";
    st.display();

    cout << "Top Element : " << st.peek() << endl;

    cout << "Is Empty : " << st.isEmpty() << endl;

    return 0;
}
