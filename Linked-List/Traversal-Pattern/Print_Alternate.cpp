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

void printAlternate(Node* head)
{
    int position = 1;

    Node* temp = head;

    while(temp != NULL)
    {
        if(position % 2 == 1)
        {
            cout << temp->data << " ";
        }

        temp = temp->next;
        position++;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);
    Node* node6 = new Node(60);
    Node* node7 = new Node(70);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    Node* head = node1;

    printAlternate(head);

    return 0;
}
