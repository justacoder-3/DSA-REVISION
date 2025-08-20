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
Node* segregateOddEvenLL1 (Node* head) {
    Node* temp = head;
    vector<int> arr;
    int i = 0;

    while (temp != NULL && temp->next != NULL) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) {
        arr.push_back(temp->data);
    }

    temp = head->next;

    while (temp != NULL && temp->next != NULL) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) {
        arr.push_back(temp->data);
    }

    temp = head;

    while (i < arr.size()) {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    return head;
}

// time complexity : O(n/2 + n/2 + n) = O(2n) => O(n)
// space complexity : O(n)

// optimal solution 
Node* segregateOddEvenLL2 (Node* head) {

}