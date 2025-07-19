// reversing an array using two variables in the reverse function
#include <bits/stdc++.h>
using namespace std;

void reverse(int i,int j,int arr1[]){
    if(i>=j){
        return;
    }
    swap(arr1[i],arr1[j]);
    reverse(i+1,j-1,arr1);
}

int main(){
    int n,i,j;
    cout<<"Enter the array size n\n";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements of array:\n";
    for(i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"The array is\n";
    for(i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    reverse(0,n-1,arr1);

    cout<<"\nThe reversed array is\n";
    for(i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}

// reversing an array using one variables in the reverse function
#include <bits/stdc++.h>
using namespace std;

void reverse(int i,int n,int arr1[]){
    if(i>=n/2){
        return;
    }
    swap(arr1[i],arr1[n-i-1]);
    reverse(i+1,n,arr1);
}

int main(){
    int n,i;
    cout<<"Enter the array size n\n";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements of array:\n";
    for(i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"The array is\n";
    for(i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    reverse(0,n,arr1);

    cout<<"\nThe reversed array is\n";
    for(i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}