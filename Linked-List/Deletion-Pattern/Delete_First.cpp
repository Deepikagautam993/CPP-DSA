#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
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

void deleteFirst(Node* &head)
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before Deletion:\n";
    printList(head);

    deleteFirst(head);

    cout << "\nAfter Deletion:\n";
    printList(head);

    return 0;
}
