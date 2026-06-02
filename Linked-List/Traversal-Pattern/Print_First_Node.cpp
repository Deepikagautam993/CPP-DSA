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

void printFirstNode(Node* head)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    cout << head->data;
}

int main()
{
    Node* node1 = new Node(7);
    Node* node2 = new Node(14);
    Node* node3 = new Node(21);

    node1->next = node2;
    node2->next = node3;

    Node* head = node1;

    printFirstNode(head);

    return 0;
}
