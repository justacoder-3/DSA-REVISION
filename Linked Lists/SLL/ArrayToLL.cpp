#include <bits/stdc++.h>
using namespace std;

struct Node{
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

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=nullptr;
    Node* current=nullptr;
    for(int i=0;i<n;i++){
        Node* newNode=new Node(arr[i]);
        if(head==nullptr){
            head=newNode;
        }
        else{
            current->next=newNode;
        }
        current=newNode;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
