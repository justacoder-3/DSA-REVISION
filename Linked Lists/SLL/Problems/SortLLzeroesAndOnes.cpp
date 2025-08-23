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

// brute force approach

Node* sortLL1 (Node* head) {
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    while (temp != NULL) {
        if (temp->data == 0) {
            count0++;
        }
        else if (temp->data == 1) {
            count1++;
        }
        else {
            count2++;
        }
        temp = temp->next;
    }

    temp = head;

    while (count0 != 0) {
        temp->data = 0;
        count0--;
        temp = temp->next;
    }
    while (count1 != 0) {
        temp->data = 1;
        count1--;
        temp = temp->next;
    }
    while (count2 != 0) {
        temp->data = 2;
        count2--;
        temp = temp->next;
    }

    return head;
}

// time complexity : O(n) [for count no of 0s, 1s and 2s] + O(n) [for inserting 0s, 1s and 2s] => O(2n) => O(n)
// space complexity O(1)

// optimal approach 
Node* sortLL2 (Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* head0 = new Node(-1);
    Node* head1 = new Node(-1);
    Node* head2 = new Node(-1);
    Node* zero = head0;
    Node* one = head1;
    Node* two = head2;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        }
        else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    zero->next = (head1->next) ? head1->next : head2->next ; // note that the question doesnt say all three 0, 1 and 2 is going to be there in the linked list
    one->next = head2->next;
    two->next = NULL;

    Node* newHead = head0->next;

    delete head0;
    delete head1;
    delete head2;

    return newHead;
}

// time complexity : O(n)
// space complexity O(1)