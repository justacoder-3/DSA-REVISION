#include <bits/stdc++.h>
using namespace std;

void rotatearray(int d,int n,int arr[]){
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n,d;
    cout<<"Enter the number of elements you want to insert : \n";
    cin >> n;
    int arr[n];
    cout<<"Enter the array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the no of places you want to rotate\n";
    cin>>d;
    rotatearray(d,n,arr);
    return 0;
}