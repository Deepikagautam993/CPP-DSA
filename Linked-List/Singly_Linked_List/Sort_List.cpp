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


void insertAtEnd(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Merge Two Sorted Lists
Node* merge(Node* left, Node* right)
{
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(left != NULL && right != NULL)
    {
        if(left->data <= right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if(left != NULL)
        tail->next = left;

    if(right != NULL)
        tail->next = right;

    return dummy->next;
}

// Merge Sort on Linked List
Node* sortList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    Node* left = sortList(head);
    Node* right = sortList(slow);

    return merge(left, right);
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);

    cout << "Original List : ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List : ";
    printList(head);

    return 0;
}
