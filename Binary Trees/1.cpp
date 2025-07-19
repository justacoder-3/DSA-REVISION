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

void postorder(Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node-> left);
    postorder(node-> right);
    cout << node-> data << " ";
}

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node-> left);
    cout << node-> data << " ";
    inorder(node-> right);
}

void preorder(Node* node) {
    if( node == NULL) {
        return;
    }
    cout << node-> data << " ";
    preorder(node-> left);
    preorder(node-> right);
}

int main() {
    struct Node* root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    root-> left-> right = new Node(4);
}



