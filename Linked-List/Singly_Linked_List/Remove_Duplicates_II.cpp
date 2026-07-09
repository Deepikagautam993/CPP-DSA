#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


ListNode* deleteDuplicates(ListNode* head) {

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;


    while(curr != NULL) {

        bool duplicate = false;

        // Check if current node has duplicates
        while(curr->next != NULL && curr->val == curr->next->val) {
            duplicate = true;
            curr = curr->next;
        }


        if(duplicate) {
            // Remove all nodes having this value
            prev->next = curr->next;
        }
        else {
            // Move prev only if no duplicate
            prev = prev->next;
        }


        curr = curr->next;
    }


    return dummy->next;
}


void printList(ListNode* head) {

    while(head != NULL) {

        cout << head->val;

        if(head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main() {

    /*
        Input:
        1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

        Output:
        1 -> 2 -> 5
    */


    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);


    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
