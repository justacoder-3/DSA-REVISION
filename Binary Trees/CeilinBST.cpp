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

int ceilInBST (Node* root, int key) {
    int ceil = -1;
    while (root != NULL) {
        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

