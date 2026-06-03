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

Node* middleNode(Node* head)
{
    int count = 0;

    Node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int middle = (count / 2) + 1;

    temp = head;

    for(int i = 1; i < middle; i++)
    {
        temp = temp->next;
    }

    return temp;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Node* head = node1;

    Node* ans = middleNode(head);

    cout << "Middle Node = " << ans->data;

    return 0;
}
