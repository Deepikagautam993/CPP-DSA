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


void deleteAtPosition(Node* &head, int position)
{
    if(head == NULL)
    {
        return;
    }

    // Delete Head
    if(position == 1)
    {
        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(temp == NULL)
    {
        return;
    }

    // Delete Tail
    if(temp->next == NULL)
    {
        temp->prev->next = NULL;
        delete temp;
        return;
    }

    // Delete Middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->next = NULL;
    temp->prev = NULL;

    delete temp;
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

    cout << "Before Deletion : ";
    printList(head);

    deleteAtPosition(head, 3);

    cout << "After Deletion : ";
    printList(head);

    return 0;
}
