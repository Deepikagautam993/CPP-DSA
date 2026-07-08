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

ListNode* swapPairs(ListNode* head) {

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;

    while (prev->next != NULL && prev->next->next != NULL) {

        ListNode* first = prev->next;
        ListNode* second = first->next;
        ListNode* nextPair = second->next;

        // Swap
        first->next = nextPair;
        second->next = first;
        prev->next = second;

        // Move prev to the end of the swapped pair
        prev = first;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = swapPairs(head);

    cout << "After Swapping: ";
    printList(head);

    return 0;
}
