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

void insertBeforeValue(Node* &head, int target, int value)
{
    // Special case: target is at head
    if(head == NULL)
        return;

    if(head->data == target)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Find previous node of target
    while(temp->next != NULL && temp->next->data != target)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        cout << "Target not found\n";
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Node* head = node1;

    cout << "Before:\n";
    printList(head);

    insertBeforeValue(head, 30, 25);

    cout << "\nAfter:\n";
    printList(head);

    return 0;
}
