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
Node* deleteMiddleNode1 (Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    int actualVal = (count/2)-1;
    temp = head;

    while (actualVal != 0) {
        temp = temp->next;
        actualVal--;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// time complexity : O(n) [for calculating counting] + O(n) [for going to previous node before middle node and in worst case it is n] => O(2n) => O(n)
// space complexity : O(1)

Node* deleteMiddleNode2 (Node* head) {
    Node* slow = head;
    Node* fast = head;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* delNode = slow->next; 
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

// time complexity : O(n) [becoz its a single pass, no 2nd time pass]
// space complexity : O(1)