#include <bits/stdc++.h>;
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> MorrisTraversal (Node* root) {
    vector<int> ans;
    Node* curr = root;
    Node* pre;
    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else {
            pre = curr->left;
            while (pre->right != NULL) {
                pre = pre->right;
            }

            pre->right = curr;
            Node* temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }
    }
    return ans;
}