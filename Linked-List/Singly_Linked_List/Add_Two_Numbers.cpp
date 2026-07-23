#include <iostream>
using namespace std;

// Node Structure
struct ListNode {
    int val;
    ListNode* next;
};

// Create New Node
ListNode* createNode(int data) {
    ListNode* newNode = new ListNode;
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at Tail
void insertAtTail(ListNode*& head, ListNode*& tail, int data) {

    ListNode* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Print Linked List
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = createNode(0);
    ListNode* curr = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

int main() {

    ListNode* head1 = NULL;
    ListNode* tail1 = NULL;

    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 3);

    ListNode* head2 = NULL;
    ListNode* tail2 = NULL;

    insertAtTail(head2, tail2, 5);
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 4);

    cout << "First List : ";
    printList(head1);

    cout << "Second List: ";
    printList(head2);

    ListNode* result = addTwoNumbers(head1, head2);

    cout << "Result     : ";
    printList(result);

    return 0;
}
