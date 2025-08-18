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

// ordinary method using stack to store all the values
bool pallindromeLL1 (Node* head) {
    Node* temp = head;
    stack<int> st;

    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (temp->data == st.top()) {
            st.pop();
            temp = temp->next;
        }
        else {
            return false;
        }
    }
    return true;
}

// time complexity : O(n) + O(n) => O(2n) => O(n)
// space complexity : O(n)

Node* reverseLL (Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
}

bool pallindromeLL2 (Node* head) {

    // finding out the middle
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) { // O(n/2)
        slow = slow->next;
        fast = fast->next->next;
    }

    // reversing the second half
    Node* newHead = reverseLL (slow->next); // O(n/2)

    // comparing first half and second half with each other
    Node* first = head;
    Node* second  = newHead;

    while (second != NULL) { // O(n/2)
        if (first->data != second->data) {
            reverseLL (newHead); // O(n/2)
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL (newHead); // O(n/2)
    return true;
}

// above method is complete 3 step process
// time complexity : O(n/2) + O(n/2) + O(n/2) + O(n/2) => O(2n) => O(n)
// space complexity : O(1) 