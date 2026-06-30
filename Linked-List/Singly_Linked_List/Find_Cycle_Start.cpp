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

// Detect + find cycle start
Node* detectCycleStart(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            // Step 2: find start
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create cycle: 5 -> 3
    fifth->next = third;

    Node* result = detectCycleStart(head);

    if(result != NULL) {
        cout << "Cycle starts at node: " << result->data << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
