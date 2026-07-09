#include <iostream>
#include <vector>
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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;


    while(list1 != NULL && list2 != NULL) {


        if(list1->val <= list2->val) {

            temp->next = list1;
            list1 = list1->next;
        }
        else {

            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if(list1 != NULL)
        temp->next = list1;

    else
        temp->next = list2;

    return dummy->next;
}

ListNode* mergeRange(vector<ListNode*>& lists, int start, int end) {

    if(start == end)
        return lists[start];

    int mid = start + (end - start) / 2;

    ListNode* left = mergeRange(lists, start, mid);

    ListNode* right = mergeRange(lists, mid + 1, end);

    return mergeTwoLists(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {

    if(lists.empty())
        return NULL;

    return mergeRange(lists, 0, lists.size()-1);
}


void printList(ListNode* head) {


    while(head != NULL) {

        cout << head->val;

        if(head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main() {


    /*
        Input:

        1 -> 4 -> 5

        1 -> 3 -> 4

        2 -> 6


        Output:

        1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

    */

    vector<ListNode*> lists;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);


    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* answer = mergeKLists(lists);

    cout << "Merged List: ";

    printList(answer);

    return 0;
}
