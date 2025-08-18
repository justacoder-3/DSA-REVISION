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
int lengthOfALoop1 (Node* head) {
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

// tortoise and hare method
int findLength (Node* slow, Node* fast) {
    int count = 1;
    fast = fast->next;
    while (fast != slow) {
        count++;
        fast = fast->next;
    }
    return count;
}

int lengthOfALoop2 (Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast= fast->next->next;
        if (slow == fast) {
            return findLength (slow, fast);
        }
    }
    return 0;
}

// time complexity : O(2n) => O(n)
// -> Detect cycle with Floyd’s algo (O(N))
// -> Count length by traversing the cycle once (O(N) worst case).
// O(2n) becomes O(n) finally becoz constants are ignored in calculating time complexity
// space complexity : O(1)