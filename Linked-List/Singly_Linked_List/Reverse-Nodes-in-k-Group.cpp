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

Node* reverseKGroup(Node* head, int k) {

    if(head == NULL)
        return NULL;


    // Check if k nodes exist
    Node* temp = head;
    int count = 0;

    while(temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }


    // Remaining nodes less than k
    if(count < k)
        return head;


    // Reverse k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    count = 0;


    while(curr != NULL && count < k) {

        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }


    // Connect remaining part
    head->next = reverseKGroup(curr, k);

    return prev;
}


// Print linked list
void printList(Node* head) {

    while(head != NULL) {

        cout << head->data << " -> ";

        head = head->next;
    }

    cout << "NULL" << endl;
}


int main() {


    // Creating list:
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);

    head->next = new Node(2);

    head->next->next = new Node(3);

    head->next->next->next = new Node(4);

    head->next->next->next->next = new Node(5);


    cout << "Original List: ";
    printList(head);

    int k = 2;

    Node* result = reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ": ";

    printList(result);

    return 0;
}
