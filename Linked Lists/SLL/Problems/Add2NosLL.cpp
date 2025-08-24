#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node (int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* add2Nos (Node* head1, Node* head2) {
    Node* dummyNode = new Node(-1);
    Node* t1 = head1;
    Node* t2 = head2;
    Node* curr = dummyNode;
    int carry = 0;

    while (t1 != NULL || t2 != NULL) {
        int sum = carry;

        if (t1) {
            sum += t1->data;
        }
        if (t2) {
            sum += t2->data;
        }

        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if (t1) {
            t1 = t1->next;
        }
        if (t2) {
            t2 = t2->next;
        }
    }

    if (carry == 1) {
        Node* newOneRequired = new Node(1);
        curr->next = newOneRequired;
    }

    return dummyNode->next;
}

// time complexity : O(max(n1, n2)) 
// space complexity : O(max(n1, n2)) => technically u see, we are not using any space coz in question they asked to store the linked list and then give the result so we are storing it.
// where n1 is the length of LL1 and n2 is the length of LL2