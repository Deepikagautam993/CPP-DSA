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


void insertAtHead(Node* &head, int data)
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

    // Connect New Node with Old Head
    newNode->next = head;

    // Last Node points to New Head
    temp->next = newNode;

    // Update Head
    head = newNode;
}

int main()
{
    Node* head = NULL;

    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Before Insertion : ";
    printList(head);

    insertAtHead(head, 5);

    cout << "After Insertion  : ";
    printList(head);

    return 0;
}
