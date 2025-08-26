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

int main () {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
}
