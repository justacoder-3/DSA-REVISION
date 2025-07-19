#include<bits/stdc++.h>
using namespace std;

void recursionBubbleSort(vector<int> &arr,int n){
    if(n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        }
    }
    recursionBubbleSort(arr,n-1);
}

int main(){
    int n;
    cout<<"Enter the number of elements : \n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    recursionBubbleSort(arr,n);
    cout<<"Elements of your array : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}