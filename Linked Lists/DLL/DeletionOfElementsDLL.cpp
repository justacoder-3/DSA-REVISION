#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
        Node (int data1,Node* next1,Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
    
        Node (int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
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

int countEl(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead (Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == nullptr) {
        delete head;
        return NULL;
    }
    else {
        Node* prev = head;
        head = head->next;
        head->prev = nullptr;
        delete prev;
        return head;
    }
}

Node* deleteTail (Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteKth (Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    int count1 = countEl(head);
    
    if (k > count1) {
        cout<< "Out of Bounds";
        return NULL;
    }

    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        if (k == count) {
            break;
        }
        temp = temp->next;
    }

    Node* front = temp->next;
    Node* back = temp->prev;

    if (front == NULL && back == NULL) {
        return NULL;
    }

    else if (back == NULL) {
        return deleteHead(head);
    }

    else if (front == NULL) {
        return deleteTail(head);
    }

    back->next = front;
    front->prev = back;
    delete temp;
    return head;
} 
void deleteNode(Node* temp) {
    // we didnt write code for deleting the head becoz that would require us to move head front making it complex, they wont ask this in interviews
    Node* back = temp->prev;
    Node* front = temp->next;

    if (temp->next == NULL) {
        back->next = nullptr;
        temp->prev = nullptr;
        delete (temp);
        return;
    }

    back->next = front;
    front->prev = back;
    temp->prev = temp->next = nullptr;
    delete (temp);
}

int main () {
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArrToDLL(arr);
    // Node* newHead1 = deleteHead(head);
    // printDLL(newHead1);
    // Node* newHead2 = deleteTail(head);
    // printDLL(newHead2);
    Node* newHead3 = deleteKth(head, 6);
    printDLL(newHead3);
}