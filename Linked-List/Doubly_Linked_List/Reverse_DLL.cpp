#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};


void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reverseDLL(Node* &head)
{

    if(head == NULL || head->next == NULL)
    {
        return;
    }

    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL)
    {
        // Swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node (which is previous after swapping)
        curr = curr->prev;
    }

    // Update head
    if(temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;

    cout << "Before Reverse : ";
    printList(head);

    reverseDLL(head);

    cout << "After Reverse  : ";
    printList(head);

    return 0;
}
