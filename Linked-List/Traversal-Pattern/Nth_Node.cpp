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

int getNthNode(Node* head, int n)
{
    Node* temp = head;
    int count = 1;

    while(temp != NULL)
    {
        if(count == n)
        {
            return temp->data;
        }

        temp = temp->next;
        count++;
    }

    return -1; // Position does not exist
}

int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(15);
    Node* node3 = new Node(25);
    Node* node4 = new Node(35);
    Node* node5 = new Node(45);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Node* head = node1;

    cout << getNthNode(head, 5);

    return 0;
}
