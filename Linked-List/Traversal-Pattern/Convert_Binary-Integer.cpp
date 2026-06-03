#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int getDecimalValue(Node* head)
{
    int ans = 0;

    Node* temp = head;

    while(temp != NULL)
    {
        ans = ans * 2 + temp->data;
        temp = temp->next;
    }

    return ans;
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(0);
    Node* node3 = new Node(1);

    node1->next = node2;
    node2->next = node3;

    Node* head = node1;

    cout << getDecimalValue(head);

    return 0;
}
