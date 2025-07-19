// Normal approach is sort the elements and find the second largest element

// Better approach is find the max element without sorting and then find second largest element
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of elements \n";
    cin>>n;
    cout<<"Enter the array : \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"Largest element is : "<<largest;
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest=arr[i];
        }
    }
    cout<<"\nSecond largest element is : "<<slargest<<"\n";
    return 0;
}

//Optimized code
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of elements \n";
    cin>>n;
    cout<<"Enter the array : \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=arr[0];
    int slargest=INT16_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    int smallest=arr[0];
    int ssmallest=INT16_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && ssmallest>arr[i]){
            ssmallest=arr[i];
        }
    }
    cout<<"Largest element is : "<<largest;
    cout<<"\nSecond Largest element is : "<<slargest;
    cout<<"\nSmallest element is : "<<smallest;
    cout<<"\nSecond Smallest element is : "<<ssmallest;
    return 0;
}
