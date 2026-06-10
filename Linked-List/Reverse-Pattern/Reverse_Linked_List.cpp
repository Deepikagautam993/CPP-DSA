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

Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    return prev;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before Reverse:\n";
    printList(head);

    head = reverseList(head);

    cout << "\nAfter Reverse:\n";
    printList(head);

    return 0;
}
