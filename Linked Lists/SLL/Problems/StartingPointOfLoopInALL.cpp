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
Node* startingPoint1 (Node* head) {
    unordered_set<Node*> st;

    Node* temp = head;
    while (temp != NULL) {
        if (st.find(temp) != st.end()) {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

// Time Complexity:
//      Each find() and insert() → O(1) average.
//      For N nodes → O(N) average time.
//      Worst case → O(N²) if many hash collisions, but rare.
// Space Complexity:
//      You may store all nodes in the set → O(N).

// optimal approach (floyd's cycle detection method)
Node* startingPoint2 (Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    // loop detection
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        // if loop detected, find the starting point
        if (slow == fast) {
            fast = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // this is the starting point of loop. Even returning the fast gives the same answer
        }
    }
    return NULL; // no loop detected
}

// time complexity : O(n)
// space complexity : O(1)