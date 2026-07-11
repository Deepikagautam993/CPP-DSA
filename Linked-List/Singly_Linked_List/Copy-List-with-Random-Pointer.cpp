#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int data)
    {
        val = data;
        next = NULL;
        random = NULL;
    }
};


void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << "Node = " << temp->val << " ";

        if(temp->random != NULL)
            cout << "Random = " << temp->random->val;
        else
            cout << "Random = NULL";

        cout << endl;

        temp = temp->next;
    }
}


Node* copyRandomList(Node* head)
{
    if(head == NULL)
        return NULL;

    // ---------------- STEP 1 ----------------
    Node* temp = head;

    while(temp != NULL)
    {
        Node* copy = new Node(temp->val);

        copy->next = temp->next;
        temp->next = copy;

        temp = copy->next;
    }

    // ---------------- STEP 2 ----------------
    temp = head;

    while(temp != NULL)
    {
        if(temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }

        temp = temp->next->next;
    }

    // ---------------- STEP 3 ----------------
    Node* dummy = new Node(-1);
    Node* copyTail = dummy;

    temp = head;

    while(temp != NULL)
    {
        Node* copy = temp->next;

        copyTail->next = copy;
        copyTail = copy;

        temp->next = copy->next;

        temp = temp->next;
    }

    return dummy->next;
}

int main()
{
    // Create Nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Next Pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Random Pointers
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List\n\n";
    printList(n1);

    Node* copyHead = copyRandomList(n1);

    cout << "\nCopied List\n\n";
    printList(copyHead);

    return 0;
}
