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

int countOccurrences(Node* head, int target)
{
    int count = 0;

    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == target)
        {
            count++;
        }

        temp = temp->next;
    }

    return count;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(10);
    Node* node4 = new Node(30);
    Node* node5 = new Node(10);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Node* head = node1;

    cout << countOccurrences(head, 10);

    return 0;
}
