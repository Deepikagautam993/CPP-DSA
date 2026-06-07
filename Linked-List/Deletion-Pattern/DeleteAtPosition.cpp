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

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void deleteAtPosition(Node* &head, int pos)
{
    if(head == NULL)
        return;

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node* delNode = temp->next;

    temp->next = delNode->next;

    delete delNode;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Before:\n";
    printList(head);

    deleteAtPosition(head, 3);

    cout << "\nAfter:\n";
    printList(head);

    return 0;
}
