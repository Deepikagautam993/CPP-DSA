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

int length(Node* head)
{
    int count = 0;

    Node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(15);
    Node* node3 = new Node(25);
    Node* node4 = new Node(35);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Node* head = node1;

    cout << "Length = " << length(head);

    return 0;
}
