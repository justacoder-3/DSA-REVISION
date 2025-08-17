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
// explanation : in the map -> mpp.find and mpp[temp] that is finding and inserting operations take O(logn) thats why above O(nlogn) whereas in unordered map the same operations take O(n)
// space complexity : O(n)

// set method
bool detectALoopSetMethod (Node* head) {
    unordered_set<Node*> st;
    Node* temp = head;

    while (temp != NULL) {
        if (st.find(temp) != st.end()) {
            return true;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

// time complexity : O(n) and O(n^2) in rare worst cases due to bad hashing
// explanation : Operations in unordered_set
//          insert(x) → O(1) average (because hash table stores it directly in a bucket).
//          find(x) → O(1) average (just check the bucket for that hash value).
//          Worst case: If hashing is bad (lots of collisions), both become O(N), but that’s rare with a good hash function.
//          So, time complexity becomes O(n * n) -> O(n^2). 
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