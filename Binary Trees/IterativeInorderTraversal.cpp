#include <bits/stdc++.h>;
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    Node (int val) {
        data = val;
        right = left = NULL;
    }
};

vector<int> iterativeInorder (Node* root) {
    stack<Node*> st;
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->data);
        curr = curr->right;
    }

    return ans;
}

// time complexity : O(n)
// space complexity : O(n) [worst case] and O(logn) [average case]
