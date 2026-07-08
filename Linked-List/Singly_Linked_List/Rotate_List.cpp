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


ListNode* rotateRight(ListNode* head, int k)
{

    if(head == NULL || head->next == NULL || k == 0)
        return head;


    // Find length and tail

    ListNode* tail = head;
    int length = 1;


    while(tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }


    k = k % length;

    if(k == 0)
        return head;


    // Make circular

    tail->next = head;


    // Find new tail

    int steps = length - k - 1;

    ListNode* newTail = head;


    while(steps--)
    {
        newTail = newTail->next;
    }


    ListNode* newHead = newTail->next;

    // Break circle

    newTail->next = NULL;

    return newHead;
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

    /*
        Input:

        1 -> 2 -> 3 -> 4 -> 5

        k = 2
    */

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, 2);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
