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

Node* intersectionPoint1 (Node* head1, Node* head2) {

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

// time complexity : O(n*a) + O(m*b) [where n is the no of nodes in first LL and m is from second LL] => O(n*1) + O(m*1) => O(n) + O(m) => O(n+m)
// where a = time complexity taken by unordered_map to insert the nodes into the map => O(1)
//       b = time complexity taken by unordered_map to compare each and every node with the intersecting node => O(1)
// in worst cases : O(n*m) [if hash collissions are present]
// space complexity : O(n) [we store only n nodes in the map where n nodes are the nodes from the first linked list]

// reducing the space complexity approach
Node* collissionPoint (Node* t1, Node* t2, int d) {
    while (d) {
        d--;
        t2 = t2->next;
    } // O(n2-n1)
    while (t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    } // O(n1) => assuming n2 is shorter and in worst case it would traverse entire array
    return t1;
}

Node* intersectionPoint2 (Node* head1, Node* head2) {
    Node* t1 = head1;
    int count1 = 0;
    Node* t2 = head2;
    int count2 = 0;

    while (t1 != NULL) {
        t1 = t1->next;
        count1++;
    } // O(n1)

    while (t2 != NULL) {
        t2 = t2->next;
        count2++;
    } // O(n2)

    if (count1 < count2) {
        return collissionPoint(head1, head2, count2-count1);
    }
    else {
        return collissionPoint(head2, head1, count1-count2);
    }
}

// time complexity : O(n1) + O(n2) + O(n2-n1) + O(n1) => O(n1+2n2)
// space complexity : O(1)

// practice
Node* collissionPoint1 (Node* t1, Node* t2, int d) {
    while (d) {
        d--;
        t2 = t2->next;
    }

    while (t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }

    return t1;
}

Node* intersectionPoint3 (Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    int count1 = 0;
    int count2 = 0;

    while (t1 != NULL) {
        count1++;
        t1 = t1->next;
    }

    while (t2 != NULL) {
        count2++;
        t2 = t2->next;
    }

    if (count2 > count1) {
        return collissionPoint1 (head1, head2, count2-count1);
    }

    else {
        return collissionPoint1 (head2, head1, count1-count2);
    }
}