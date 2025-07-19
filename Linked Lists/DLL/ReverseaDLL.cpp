#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
    
        Node (int data1, Node* prev1, Node* next1) {
            data = data1;
            prev = prev1;
            next = next1;
        }
    
        Node (int data1) {
            data = data1;
            prev = nullptr;
            next = nullptr;
        }
    };
    

Node* convertArrToDLL (vector <int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL (Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// inefficient function coz time and space complexity is taken more    
Node* reverseDLL1 (Node* head) {
    Node* temp = head;
    stack <int> st;

    while (temp!=NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp!=NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node* reverseDLL2 (Node* head) {
    Node* temp = NULL;
    Node* current = head;
    
    while (current!=NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }
    return temp->prev;
}

int main () {
    vector <int> arr = {1,2,3,4,5};
    Node* head1 = convertArrToDLL(arr);
    // Node* head2 = reverseDLL1(head1);
    // printDLL(head2);
    Node* head3 = reverseDLL2(head1);
    printDLL(head3);
}