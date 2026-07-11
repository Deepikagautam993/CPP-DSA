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

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}


void deleteNode(Node* &head, int value)
{
   
    if(head == NULL)
    {
        return;
    }

    // ---------- Single Node ----------
    if(head->data == value && head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    // ---------- Delete Head ----------
    if(head->data == value)
    {
        Node* last = head;

        while(last->next != head)
        {
            last = last->next;
        }

        last->next = head->next;

        Node* deleteNode = head;
        head = head->next;

        delete deleteNode;
        return;
    }

    // ---------- Delete Middle / Tail ----------
    do
    {
        prev = curr;
        curr = curr->next;
    }
    while(curr != head && curr->data != value);

    // Value not found
    if(curr == head)
    {
        cout << "Value not found!" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original List : ";
    printList(head);

    deleteNode(head, 30);

    cout << "After Deleting 30 : ";
    printList(head);

    deleteNode(head, 10);

    cout << "After Deleting 10 : ";
    printList(head);

    deleteNode(head, 40);

    cout << "After Deleting 40 : ";
    printList(head);

    return 0;
}
