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


void insertAtTail(Node* &head, int data)
{
    Node* newNode = new Node(data);

    // Empty List
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    printList(head);

    return 0;
}
