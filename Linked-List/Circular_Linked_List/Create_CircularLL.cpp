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


void createCircularLL(Node* &head, int data)
{
    Node* newNode = new Node(data);

    
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

    createCircularLL(head, 10);
    createCircularLL(head, 20);
    createCircularLL(head, 30);
    createCircularLL(head, 40);

    cout << "Circular Linked List : ";
    printList(head);

    return 0;
}
