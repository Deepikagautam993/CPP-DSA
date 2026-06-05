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

void insertAtBeginning(Node* &head, int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;

    head = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* node1 = new Node(100);
    Node* node2 = new Node(200);
    Node* node3 = new Node(300);

    node1->next = node2;
    node2->next = node3;

    Node* head = node1;

    insertAtBeginning(head, 50);

    printList(head);

    return 0;
}
