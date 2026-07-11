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


void deleteAtTail(Node* &head)
{
    // Empty List
    if(head == NULL)
    {
        return;
    }

    // Only One Node
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    // Move to Last Node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    temp->prev = NULL;

    delete temp;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Connect Nodes
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;

    cout << "Before Deletion : ";
    printList(head);

    deleteAtTail(head);

    cout << "After Deletion : ";
    printList(head);

    return 0;
}
