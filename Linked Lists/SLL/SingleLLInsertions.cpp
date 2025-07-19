#include <bits/stdc++.h>
using namespace std;

class Node {
public:
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

void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
} 

Node* convertArrayToLL (vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size() ; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* insertionAtBeginning(Node* head, int element) {
    Node* temp = new Node(element, head);
    return temp;
}

Node* insertionAtEnd(Node* head, int element) {
    if(head == NULL) {
        return new Node(element);
    }
    Node* temp = head;
    Node* newEl = new Node(element);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newEl;
    return head;
}

Node* insertElatK(Node* head, int el, int k) {

    if(head == NULL) {
        if(k==1){
            return new Node(el);
        }
        return NULL;
    }

    if(k == 1) {
        Node* temp = new Node(el,head);
        return temp;
    }

    else {
        Node* temp = head;
        Node* newel = new Node(el);
        int count = 0;
        while (temp != NULL) {
            count++;
            if(count == k-1) {
                newel->next = temp->next;
                temp->next = newel;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
}

Node* byValue(Node* head, int el, int val) {
    if(head == NULL) {
        return NULL;
    }

    if(head->data == val) {
        Node* temp = new Node(el,head);
        return temp;
    }

    else {
        Node* temp = head;
        Node* newel = new Node(el);
        while (temp->next != NULL) {
            if(temp->next->data == val) {
                newel->next = temp->next;
                temp->next = newel;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
}

int main () {
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArrayToLL (arr);
    // cout << head->data;
    // Node* insertedEl = insertionAtBeginning(head,5);
    // cout << " " << insertedEl->data;
    // Node* insertEnd = insertionAtEnd(head,8);
    // printList(insertEnd);
    Node* insertk = insertElatK(head,8,9);
    printList(insertk);
}


