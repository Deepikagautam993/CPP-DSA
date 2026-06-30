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

Node* reverseBetween(Node* head, int left, int right)
{
    if(head == NULL || left == right)
        return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;

    // Move prev to node before left position
    for(int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    Node* curr = prev->next;
    Node* start = curr;      // First node of reversal part

    Node* prevNode = NULL;

    // Reverse right-left+1 nodes
    for(int i = 0; i < right - left + 1; i++)
    {
        Node* next = curr->next;

        curr->next = prevNode;

        prevNode = curr;
        curr = next;
    }

    // Reconnect
    prev->next = prevNode;
    start->next = curr;

    head = dummy->next;
    delete dummy;

    return head;
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
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Before Reverse:" << endl;
    printList(head);

    int left = 2;
    int right = 4;

    head = reverseBetween(head, left, right);

    cout << "\nAfter Reverse:" << endl;
    printList(head);

    return 0;
}
