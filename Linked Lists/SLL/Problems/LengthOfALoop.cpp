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

// normal map method
int lengthOfALoop (Node* head) {
    Node* temp = head;
    map <Node*, int> st;
    int count = 1;
    while (temp != NULL) {
        if (st.find(temp) != st.end()) {
            int value = st[temp];
            return (count-value);
        }
        st[temp] = count;
        count++;
        temp = temp->next;
    }
    return 0;
}

// time complexity : O(n)
// space complexity : O(n)