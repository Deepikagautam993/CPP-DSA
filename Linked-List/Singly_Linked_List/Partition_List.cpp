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


ListNode* partition(ListNode* head, int x) {

    ListNode* smallDummy = new ListNode(0);
    ListNode* largeDummy = new ListNode(0);

    ListNode* small = smallDummy;
    ListNode* large = largeDummy;


    while(head != NULL) {

        if(head->val < x) {

            small->next = head;
            small = small->next;

        }
        else {

            large->next = head;
            large = large->next;

        }

        head = head->next;
    }


    // Break old links to avoid cycle
    large->next = NULL;


    // Join two lists
    small->next = largeDummy->next;


    return smallDummy->next;
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


    ListNode* head = new ListNode(1);

    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);


    cout << "Original List: ";
    printList(head);


    head = partition(head, 3);


    cout << "Partitioned List: ";
    printList(head);


    return 0;
}
