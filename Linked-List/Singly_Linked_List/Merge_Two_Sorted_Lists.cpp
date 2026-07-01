#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


Node* mergeTwoLists(Node* l1, Node* l2) {

    Node dummy(0);   // dummy node
    Node* tail = &dummy;

    while(l1 != NULL && l2 != NULL) {

        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    // attach remaining nodes
    if(l1 != NULL) tail->next = l1;
    if(l2 != NULL) tail->next = l2;

    return dummy.next;
}


void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // List 1: 1 -> 4 -> 7
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(7);

    // List 2: 2 -> 3 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(3);
    l2->next->next = new Node(6);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Node* merged = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
