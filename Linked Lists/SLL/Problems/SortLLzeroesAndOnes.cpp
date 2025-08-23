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