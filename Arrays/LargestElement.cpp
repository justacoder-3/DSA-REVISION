//Most normal approach is to sort the elements in ascending order and pick the last element

//Normal Approach
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"No. of elements in your array ? \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of your array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Your array is : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"\nYour largest element is : "<<largest;
    return 0;
}

//Optimized Code
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"No. of elements in your array ? \n";
    cin>>n;
    int arr[n];
    int largest;
    cout<<"Enter the elements of your array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0 || arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"Your array is : \n";
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
    cout<<"\nLargest element is : "<<largest;
}
