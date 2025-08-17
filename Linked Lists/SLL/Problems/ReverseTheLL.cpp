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

// iterative method
// brute force approach (brute force in the sense, this does not manipulate the pointers of linked list but instead reverses the data)
void reverseTheLL1 (Node* head) {
    Node* temp = head;
    stack<int> st;
    
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        temp = temp->next;
        st.pop();
    }
}

// time complexity : O(2n)
// space complexity : O(n)

// optimal approach (this manipulates the pointers of the linked list)
Node* reverseTheLL2 (Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev; // here prev becomes the head at last
}

// time complexity : O(n)
// space complexity : O(1)

// recursive approach
Node* reverseTheLL3 (Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseTheLL3(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// time complexity : O(n)
// space complexity : O(n)
