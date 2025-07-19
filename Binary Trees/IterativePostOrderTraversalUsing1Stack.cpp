#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int val) {
        int data = val;
        left = right = NULL;
    }
};

// vector<int> postOrderUsing1Stack (Node* root) {
//     vector<int> ans;
//     if (root == NULL) {
//         return ans;
//     }
//     stack<Node*> st;
//     Node* curr = root;
//     while (curr != NULL || !st.empty()) {
//         if (curr != NULL) {
//             st.push(curr);
//             curr = curr->left;
//         }
//         else {
//             Node* temp = st.top()->right;
//             if(temp == NULL) {
//                 temp = st.top();
//                 st.pop();
//                 ans.push_back(temp->data);
//                 while (!st.empty() && temp == st.top()->right) {
//                     temp = st.top();
//                     st.pop();
//                     ans.push_back(temp->data);
//                 }
//             }
//             else {
//                 curr = temp;
//             }
//         }
//     }
//     return ans;
// }

vector<int> postOrderUsing1Stack (Node* root) {
    vector<int> ans;
    stack<Node*> st;
    if (root == NULL) {
        return ans;
    }
    Node* curr = root;
    while (!st.empty() || curr!= NULL) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && st.top()->right == temp) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return ans;
}