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

void insertAfterValue(Node* &head, int target, int value)
{
    Node* temp = head;

    // Search target node
    while(temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Target value not found!" << endl;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
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

    cout << "Before Insertion:\n";
    printList(head);

    insertAfterValue(head, 20, 25);

    cout << "\n\nAfter Insertion:\n";
    printList(head);

    return 0;
}
