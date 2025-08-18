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

// ordinary method using map
Node* middleOfaLL1 (Node* head) {
    Node* temp = head;
    map <int, Node*> mp;
    int count = 0;
    while (temp != NULL) {
        count++;
        mp[count] = temp;
        temp = temp->next;
    }

    int mid;
    if (count % 2 == 0) {
        mid = count/2;
    }
    else {
        mid = (count/2) + 1;
    }
    return mp[mid];
}

// time complexity : O(n) + o (n) => O(2n) => O(n)
// space complexity : O(n)

// using tortoise and hare method
Node* middleOfaLL2 (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// time complexity : O(n/2) => O(n) but its better to say O(n/2) only in interview
// space complexity : O(1)