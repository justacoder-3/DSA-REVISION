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

Node* intersectionPoint (Node* head1, Node* head2) {

    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    unordered_map<Node*, int> mpp;

    while (temp1 != NULL) {
        mpp[temp1] = 1;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        if (mpp.find(temp2) != mpp.end()) {
            return temp2;
        }
        temp2 = temp2->next;
    }

    return NULL;
}

// time complexity : O(n*a) + O(m*b) + O(n+m) [where n is the no of nodes in first LL and m is from second LL] => O(1) + O(1) + O(n+m) => O(n+m)
// where a = time complexity taken by unordered_map to insert the nodes into the map => O(1)
//       b = time complexity taken by unordered_map to compare each and every node with the intersecting node => O(1)
// in worst cases : O(n*m) [if hash collissions are present]
// space complexity : O(n) [we store only n nodes in the map where n nodes are the nodes from the first linked list]