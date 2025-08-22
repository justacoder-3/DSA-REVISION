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
Node* removeNthNode1 (Node* head, int n) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int res = count - n - 1;
    temp = head;

    if (count == n) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    while (res != 0) {
        res--;
        temp = temp->next;
    }

    Node* delNode = temp->next;
    if (temp->next != NULL) {
        temp->next = temp->next->next;
        delete delNode;
    }

    return head;
}

// time complexity : O(len) + O(len - n) => len is length of the array and n is the no given 
// => worst case scenario time complexity is O(2n)
// space complexity : O(1)

// optimal solution
Node* removeNthNode2 (Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i<n; i++) {
        fast = fast->next;
    }

    if (fast == NULL) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    if (slow->next != NULL) {
        slow->next = slow->next->next;
        delete delNode;
    }

    return head;
}

// time complexity : O(length) becoz finally we see, at first the fast pointer travelsn till n, then the remaining, so it travely only the complete length of the array
// space complexity : O(1)


