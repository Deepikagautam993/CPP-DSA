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

Node* getIntersection(Node* headA, Node* headB) {

    if(headA == NULL || headB == NULL)
        return NULL;

    Node* a = headA;
    Node* b = headB;

    while(a != b) {

        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a;
}

void printList(Node* head) {

    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {

    // Shared part (intersection)
    Node* common = new Node(8);
    common->next = new Node(9);

    // List A: 1 -> 2 -> 8 -> 9
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = common;

    Node* headB = new Node(3);
    headB->next = new Node(4);
    headB->next->next = new Node(5);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    Node* intersection = getIntersection(headA, headB);

    if(intersection != NULL)
        cout << "Intersection Node: " << intersection->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}
