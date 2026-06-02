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

int sumOfNodes(Node* head)
{
    int sum = 0;

    Node* temp = head;

    while(temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    node1->next = node2;
    node2->next = node3;

    Node* head = node1;

    cout << sumOfNodes(head);

    return 0;
}
