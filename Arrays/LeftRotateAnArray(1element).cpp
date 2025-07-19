#include <bits/stdc++.h>
using namespace std;

void leftrotate(int n,int arr[]){
    int i=0;
    int temp=arr[0];
    for(int j=1;j<n;j++){
        arr[i]=arr[j];
        i++;
    }
    arr[n-1]=temp;
}

//OR

void leftrotate(int n,int arr[]){
    int temp=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

int main(){
    int n;
    cout << "Enter the number of elements you want to insert : \n";
    cin >> n;
    int arr[n];
    cout<<"Enter the array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    leftrotate(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}