#include <bits/stdc++.h>;
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

// general search
Node* searchInBST (Node* root, int n) {
    if (root == NULL) {
        return NULL;
    }
    while (root != NULL && root->data != n) {
        root = n < root->data ? root -> left : root -> right;
    }
    return root;
}

// minimum element search
int minElementSearchBST (Node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// maximum element search
int maxElementSearchBST (Node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}