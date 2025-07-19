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

// vector<int> IterativeInorderTraversal (Node* root) {
//     stack<Node*> st;
//     Node* node = root;
//     vector<int> ans;
//     while (true) {
//         if (node != NULL) {
//             st.push(node);
//             node = node->left;
//         }
//         else {
//             if (st.empty() == true) {
//                 break;
//             }
//             node = st.top();
//             st.pop();
//             ans.push_back(node->data);
//             node = node->right;
//         } 
//     }
//     return ans;
// }

vector<int> temp (Node* root) {
    stack<Node*> st;
    Node* node = root;
    vector<int> ans;
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->right;
        }
        else {
            if (st.empty()) {
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->left;
        }
    }
    return ans;
}
