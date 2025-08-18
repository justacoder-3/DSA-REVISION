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
bool pallindromeLL (Node* head) {
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

// time complexity : O(n)
// space complexity : O(n)