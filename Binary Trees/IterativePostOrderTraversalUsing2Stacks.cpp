#include <bits/stdc++.h>
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

vector<int> postOrderUsing2Stacks (Node* root) {
    vector<int> ans;
    stack<Node*> s1, s2;
    if (root == NULL) {
        return ans;
    }
    s1.push(root);
    while (!s1.empty()) {
        Node* curr = s1.top();
        s2.push(curr);
        s1.pop();
        if (curr->left != NULL) {
            s1.push(curr->left);
        }
        if (curr->right != NULL) {
            s1.push(curr->right);
        }
    }
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}