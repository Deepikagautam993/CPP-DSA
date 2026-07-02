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

Node* reverseList(Node* head) {

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {

        Node* next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    return prev;
}

bool isPalindrome(Node* head) {

    if(head == NULL || head->next == NULL)
        return true;


    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }


    // Step 2: Reverse second half
    Node* secondHalf = reverseList(slow);


    // Step 3: Compare both halves
    Node* firstHalf = head;

    while(secondHalf != NULL) {

        if(firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }


    return true;
}


void printList(Node* head) {

    while(head != NULL) {

        cout << head->data << " -> ";

        head = head->next;
    }

    cout << "NULL" << endl;
}


int main() {

    Node* head = new Node(1);

    head->next = new Node(2);

    head->next->next = new Node(2);

    head->next->next->next = new Node(1);


    cout << "Linked List: ";
    printList(head);


    if(isPalindrome(head)) {

        cout << "Palindrome" << endl;

    } else {

        cout << "Not Palindrome" << endl;
    }

    return 0;
}
