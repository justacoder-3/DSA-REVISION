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
void reverseTheLL (Node* head) {
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

