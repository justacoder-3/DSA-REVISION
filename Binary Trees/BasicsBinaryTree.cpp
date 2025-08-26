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

// postorder - left right root
void postorder(Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node-> left);
    postorder(node-> right);
    cout << node-> data << " ";
}

// inorder - left root right
void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node-> left);
    cout << node-> data << " ";
    inorder(node-> right);
}

// preorder - (root left right)
void preorder(Node* node) {
    if( node == NULL) {
        return;
    }
    cout << node-> data << " ";
    preorder(node-> left);
    preorder(node-> right);
}
// time complexity : O(n)
// space complexity : O(height of the tree) -> O(n) [in worst case]

// leetcode format
vector<int> preorder2 (Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<int> result;
    result.push_back(root->data);

    vector<int> left = preorder2(root->left);
    result.insert(result.end(), left.begin(), left.end());

    vector<int> right = preorder2(root->right);
    result.insert(result.end(), right.begin(), right.end());

}

int main() {
    struct Node* root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    root-> left-> right = new Node(4);
}



