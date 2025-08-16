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

// map method
bool detectALoop1 (Node* head) {
    map<Node*, int> mpp;
    Node* temp = head;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// time complexity : O(nlogn) -> if map is used and O(n) -> if unordered map is used
// in the map -> mpp.find and mpp[temp] that is finding and inserting operations take O(logn) thats why above O(nlogn) whereas in unordered map the same operations take O(n)
// space complexity : O(n)

// optimal approach (tortoise & hare method)
bool detectALoop2 (Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

// time complexity : O(n)
// space complexity : O(1)