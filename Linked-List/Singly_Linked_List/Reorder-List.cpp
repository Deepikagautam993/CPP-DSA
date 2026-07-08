#include <iostream>
using namespace std;

class ListNode {

public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};


void reorderList(ListNode* head)
{

    if(head == NULL || head->next == NULL)
        return;


    // Step 1: Find Middle
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }


    // Step 2: Split
    ListNode* second = slow->next;
    slow->next = NULL;


    // Step 3: Reverse Second Half

    ListNode* prev = NULL;
    ListNode* curr = second;

    while(curr != NULL)
    {
        ListNode* nextNode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }
    second = prev;


    // Step 4: Merge

    ListNode* first = head;

    while(second != NULL)
    {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }

}

void printList(ListNode* head)
{

    while(head != NULL)
    {
        cout << head->val;

        if(head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main()
{

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    cout << "Original List: ";
    printList(head);

    reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
