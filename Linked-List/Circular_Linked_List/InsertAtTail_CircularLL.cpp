#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};


void printList(Node* head)
{
    if(head == NULL)
    {
        cout << "List is Empty!" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}


void insertAtTail(Node* &head, int data)
{
    Node* newNode = new Node(data);

    // Empty List
    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;

    // Go to Last Node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Before Insertion : ";
    printList(head);

    insertAtTail(head, 50);

    cout << "After Insertion  : ";
    printList(head);

    return 0;
}
