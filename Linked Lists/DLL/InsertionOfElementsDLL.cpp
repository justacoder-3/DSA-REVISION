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

void printDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* insertBeforeHead (Node* head, int val) {
    Node* newHead = new Node(val, nullptr, head);
    head->prev = newHead;
    return newHead;
};

Node* insertBeforeTail (Node* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        return insertBeforeHead(head,val);
        // Node* newHead = new Node(val, nullptr, head);
        // head->prev = newHead;
        // return newHead;
    }


    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    };
    Node* newNode = new Node(val, temp, temp->next);
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

int countEl(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* insertAtK (Node* head, int val, int k) {
    if (head == NULL) {
        return NULL;
    }

    int count1 = countEl(head);
    if (k > count1) {
        cout << "Get Out";
        return NULL;
    }

    if (head->next == nullptr) {
        return insertBeforeHead(head,val);
    }

    Node* temp = head;
    int count = 0;

    while (temp!=NULL) {
        count++;
        if (count == k) {
            break;
        }
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        return insertBeforeTail(head, val);
    }

    Node* back = temp->prev;
    Node* newNode = new Node(val, back, temp);
    back->next = newNode;
    temp->prev = newNode;
    return head;
}

void insertBeforeNode (Node* node, int val) {
    Node* back = node->prev;
    Node* newNode = new Node(val, back, node);
    back->next = newNode;
    node->prev = newNode;
}

int main () {
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArrToDLL(arr);
    // Node* newHead1 = insertBeforeHead(head, 7);
    // printDLL(newHead1);
    // Node* newHead2 = insertBeforeTail(head, 100);
    // printDLL(newHead2);
    // Node* newHead3 = insertAtK(head, 100, 6);
    // printDLL(newHead3);
    insertBeforeNode(head->next->next, 5);
    printDLL(head);
    return 0;
}