#include <bits/stdc++.h>
using namespace std;

void selectionsort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int minimum=i;
        for(int j=i;j<n;j++){
            if(arr[minimum]>arr[j]){
                minimum=j;
            }
        }
        int temp=arr[minimum];
        arr[minimum]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int n;
    cout << "Enter the number of elements you want to insert : \n";
    cin >> n;
    int arr[n];
    int arr2[n];
    cout<<"Enter the array : \n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    selectionsort(n, arr);
    cout<<"Sorted array is : \n";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nCopied array is : \n";
    int same=1;
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    for(int i=0;i<n;i++){
        if(arr2[i]!=arr[i]){
            same=0;
            break;
        }
    }
    if(same==0){
        cout<<"\nThe array is not sorted\n";
    }
    else{
        cout<<"\nThe array is sorted\n";
    }
    return 0;
}


//Optimized code
#include <bits/stdc++.h>
using namespace std;

//Striver's logic
bool checkarraysorted(int n,int arr[]){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

//My logic
bool checkarraysorted(int n,int arr[]){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout << "Enter the number of elements you want to insert : \n";
    cin >> n;
    int arr[n];
    cout<<"Enter the array : \n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool check=checkarraysorted(n,arr);
    if(check==0){
        cout<<"False";
    }
    else{
        cout<<"True";
    }
}
