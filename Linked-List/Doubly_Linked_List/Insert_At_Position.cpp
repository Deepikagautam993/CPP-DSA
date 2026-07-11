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


void insertAtPosition(Node* &head, int position, int data)
{
    
    if(head == NULL)
    {
        if(position == 1)
        {
            head = new Node(data);
        }
        return;
    }

    Node* newNode = new Node(data);

    // Insert at Head
    if(position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Move to (position - 1)th node
    while(count < position - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Insert at Tail
    if(temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    // Insert in Middle
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    Node* head = NULL;

    insertAtPosition(head, 1, 10);
    insertAtPosition(head, 2, 20);
    insertAtPosition(head, 3, 40);
    insertAtPosition(head, 3, 30);

    printList(head);

    return 0;
}
