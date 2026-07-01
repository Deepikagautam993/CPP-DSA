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


Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return slow; // meeting point
        }
    }
    return NULL;
}


Node* getCycleStart(Node* head, Node* meetingPoint) {
    Node* slow = head;
    Node* fast = meetingPoint;

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


void removeCycle(Node* head) {
    Node* meetingPoint = detectCycle(head);

    if(meetingPoint == NULL) return; // no cycle

    Node* cycleStart = getCycleStart(head, meetingPoint);

    Node* temp = cycleStart;

    // find last node in cycle
    while(temp->next != cycleStart) {
        temp = temp->next;
    }

    // break cycle
    temp->next = NULL;
}


void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {

    // Creating nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

   
    sixth->next = third;

    cout << "Before removing cycle: " << endl;

    Node* check = detectCycle(head);
    if(check != NULL)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    removeCycle(head);

    cout << "After removing cycle: " << endl;
    printList(head);

    return 0;
}
