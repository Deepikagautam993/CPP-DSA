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

Node* mergeNodes(Node* head)
{
    Node* dummy = new Node(0);
    Node* tail = dummy;

    int sum = 0;

    head = head->next;

    while(head != NULL)
    {
        if(head->data != 0)
        {
            sum += head->data;
        }
        else
        {
            tail->next = new Node(sum);
            tail = tail->next;

            sum = 0;
        }

        head = head->next;
    }

    return dummy->next;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* n1 = new Node(0);
    Node* n2 = new Node(3);
    Node* n3 = new Node(1);
    Node* n4 = new Node(0);
    Node* n5 = new Node(4);
    Node* n6 = new Node(5);
    Node* n7 = new Node(2);
    Node* n8 = new Node(0);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Node* head = n1;

    Node* ans = mergeNodes(head);

    printList(ans);

    return 0;
}
