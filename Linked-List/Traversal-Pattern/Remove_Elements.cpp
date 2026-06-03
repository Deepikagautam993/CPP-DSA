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

Node* removeElements(Node* head, int val)
{
    Node* dummy = new Node(-1);
    dummy->next = head;

    Node* prev = dummy;
    Node* curr = head;

    while(curr != NULL)
    {
        if(curr->data == val)
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy->next;
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
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(6);
    Node* node4 = new Node(3);
    Node* node5 = new Node(4);
    Node* node6 = new Node(5);
    Node* node7 = new Node(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    Node* head = node1;

    head = removeElements(head, 6);

    printList(head);

    return 0;
}
