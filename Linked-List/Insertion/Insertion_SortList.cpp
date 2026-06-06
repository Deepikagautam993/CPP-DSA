#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* insertionSortList(Node* head) {

    Node* sorted = NULL;

    while(head != NULL) {

        Node* curr = head;
        head = head->next;

        if(sorted == NULL || curr->val < sorted->val) {
            curr->next = sorted;
            sorted = curr;
        }
        else {
            Node* temp = sorted;

            while(temp->next != NULL && temp->next->val < curr->val) {
                temp = temp->next;
            }

            curr->next = temp->next;
            temp->next = curr;
        }
    }

    return sorted;
}

// helper print
void print(Node* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Before:\n";
    print(head);

    head = insertionSortList(head);

    cout << "After:\n";
    print(head);

    return 0;
}
