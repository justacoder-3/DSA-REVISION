#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val; 
    Node* right;
    Node* left;
    Node (int data) {
        val = data;
        left = right = NULL;
    }
};

string serialize (Node* root) {
    if (root == NULL) {
        return "";
    }

    string str = "";

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            str.append("#,");
        }
        else {
            str.append(to_string(curr->val)+",");
        }

        if (curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return str;
}

Node* deserialize (string data) {
    stringstream s(data);
    string str;
    getline(s, str, ',');

    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#") {
            curr->left = NULL;
        }
        else {
            Node* leftNode = new Node(stoi(str));
            curr->left = leftNode;
        }

        getline(s, str, ',');

        if(str == "#") {
            curr->right = NULL;
        }
        else {
            Node* rightNode = new Node(stoi(str));
            curr->right = rightNode;
        }
    }
    return root;
}