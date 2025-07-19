#include<bits/stdc++.h>
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
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int value;

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

    temp=head;
    cout<<"\nGive an element to be searched : \n";
    cin>>value;
    bool found=false;

    while(temp!=nullptr){
        if(temp->data==value){
            cout<<value<<" Element found \n";
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(found!=true){
        cout<<"Element not found\n";
    }
    
    return 0;
}