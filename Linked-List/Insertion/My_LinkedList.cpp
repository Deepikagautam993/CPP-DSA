#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

// Linked List Class
class MyLinkedList {
private:
    Node* head;

public:
    MyLinkedList() {
        head = NULL;
    }

    // get value at index
    int get(int index) {
        Node* temp = head;

        for(int i = 0; i < index; i++) {
            if(temp == NULL) return -1;
            temp = temp->next;
        }

        if(temp == NULL) return -1;
        return temp->val;
    }

    // insert at head
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // insert at tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // insert at index
    void addAtIndex(int index, int val) {

        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            if(temp == NULL) return;
            temp = temp->next;
        }

        if(temp == NULL) return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete at index
    void deleteAtIndex(int index) {

        if(head == NULL) return;

        if(index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            if(temp == NULL) return;
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL) return;

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // print list (for testing)
    void printList() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

// MAIN FUNCTION
int main() {

    MyLinkedList list;

    cout << "Adding at head: 1\n";
    list.addAtHead(1);
    list.printList();

    cout << "Adding at tail: 3\n";
    list.addAtTail(3);
    list.printList();

    cout << "Adding 2 at index 1\n";
    list.addAtIndex(1, 2);
    list.printList();

    cout << "Get index 1: " << list.get(1) << endl;

    cout << "Delete index 1\n";
    list.deleteAtIndex(1);
    list.printList();

    cout << "Get index 1: " << list.get(1) << endl;

    return 0;
}
