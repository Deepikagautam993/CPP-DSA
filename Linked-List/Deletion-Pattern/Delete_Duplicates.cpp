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

Node* deleteDuplicates(Node* head)
{
    Node* curr = head;

    while(curr != NULL && curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* delNode = curr->next;
            curr->next = curr->next->next;
            delete delNode;
        }
        else
        {
            curr = curr->next;
        }
    }

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
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    cout << "Before:\n";
    printList(head);

    head = deleteDuplicates(head);

    cout << "\nAfter:\n";
    printList(head);

    return 0;
}
