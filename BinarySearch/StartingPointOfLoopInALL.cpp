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
Node* startingPoint (Node* head) {
    map<Node*, int> mpp;

    Node* temp = head;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}