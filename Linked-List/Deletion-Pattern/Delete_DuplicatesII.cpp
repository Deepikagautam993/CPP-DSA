#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* deleteDuplicatesII(Node* head)
{
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;
    Node* curr = head;

    while(curr != NULL)
    {
        if(curr->next != NULL &&
           curr->data == curr->next->data)
        {
            int dup = curr->data;

            while(curr != NULL &&
                  curr->data == dup)
            {
                curr = curr->next;
            }

            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    head = dummy->next;
    delete dummy;

    return head;
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);

    cout << "Before:\n";
    printList(head);

    head = deleteDuplicatesII(head);

    cout << "\nAfter:\n";
    printList(head);

    return 0;
}
