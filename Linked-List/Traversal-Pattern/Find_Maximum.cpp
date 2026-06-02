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

int findMaximum(Node* head)
{
    if(head == NULL)
        return -1;

    int maxi = head->data;

    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data > maxi)
        {
            maxi = temp->data;
        }

        temp = temp->next;
    }

    return maxi;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(50);
    Node* node3 = new Node(20);
    Node* node4 = new Node(70);
    Node* node5 = new Node(30);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Node* head = node1;

    cout << findMaximum(head);

    return 0;
}
