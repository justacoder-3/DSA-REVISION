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

Node* removeNthNode (Node* head, int n) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int res = count - n - 1;
    temp = head;

    if (count == n) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    while (res != 0) {
        res--;
        temp = temp->next;
    }

    Node* delNode = temp->next;
    if (temp->next != NULL) {
        temp->next = temp->next->next;
        delete delNode;
    }

    return head;
}