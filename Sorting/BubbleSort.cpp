#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int n,int arr[]){
    for(int i=n-1;i>=0;i--){
        int swapped=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements : \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(n,arr);
    cout<<"Elements of your array : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
