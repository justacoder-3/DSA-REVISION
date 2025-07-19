#include <bits/stdc++.h>
using namespace std;

void selectionSort(int n, int arr[])
{
    for (int i=0;i<=n-2;i++){
        int minimum=i;
        for (int j=i;j<=n-1;j++){
            if (arr[minimum]>arr[j]){
                minimum=j;
            }    
        }
        int temp=arr[minimum];
        arr[minimum]=arr[i];
        arr[i]=temp;
    }
}


int main()
{
    int n;
    cout << "Enter the number of elements you want to insert : \n";
    cin >> n;
    int arr[n];
    cout<<"Enter the array : \n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(n, arr);
    cout<<"Sorted array is : \n";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}