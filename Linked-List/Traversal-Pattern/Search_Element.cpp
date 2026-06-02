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

bool searchElement(Node* head, int target)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == target)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Node* head = node1;

    if(searchElement(head, 30))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
