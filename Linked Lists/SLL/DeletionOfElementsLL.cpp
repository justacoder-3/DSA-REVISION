#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* arrayToLL(vector <int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteElement(Node* head, int k) {
    if(head == NULL) {
        return head;
    }
    
    else if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    else {
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;
        while(temp != NULL) {
            count++;
            if(count == k) {
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head = arrayToLL(arr);
    Node* element = deleteElement(head, -1);
    printList(element);
}


// Node* deleteE(Node* head, int k) {
//     if(head == NULL) {
//         return NULL;
//     } 
//     if(k == 1) {
//         Node* temp = head;
//         head = head->next;
//         free(temp);
//         return head;
//     }
//     else{
//         Node* prev = NULL;
//         Node* temp = head;
//         int count = 0;
//         while(temp != NULL) {
//             count++;
//             if(count == k) {
//                 prev->next = prev->next->next;
//                 free(temp);
//                 break;
//             }
//             prev = temp;
//             temp = temp->next;
//         }
//         return head;
//     }
// }
