#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node (int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* reverse (Node* head) {

}

Node* add1ToLL (Node* head) {
    head = reverse(head); // O(n)
    Node* temp = head;
    int carry = 1;

    while (temp != NULL) { // O(n)
        temp->data = temp->data + carry;

        if (temp->data < 10) {
            carry = 0;
            break;
        }

        else {
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    head = reverse(head); // O(n)
    return head;
}
// time complexity : O(n+n+n) => O(3n)
// space complexity : O(1)

// practice code
Node* add1ToLL2 (Node* head) {
    head = reverse(head); 
    Node* temp = head;
    int carry = 1;

    while (temp != NULL) { 
        temp->data += carry;

        if (temp->data < 10) {
            carry = 0;
            break;
        }

        else {
            carry = 1;
            temp->data = 0;
        }

        temp = temp->next;
    }

    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    head = reverse(head); 
    return head;
}