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

vector<int> iterativePreorder (Node* root) {
    stack<Node*> st;
    st.push(root);
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        ans.push_back(node->data);

        if (node->right) {
            st.push(node->right);
        }

        if (node->left) {
            st.push(node->left);
        }
    }
    return ans;
}

// time complexity : O(n)
// space complexity : O(n) [worst case] and O(logn) [average case]

