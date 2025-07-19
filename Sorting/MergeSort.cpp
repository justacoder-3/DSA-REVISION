#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int high,int mid){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,high,mid);
}

int main(){
    int n;
    cout << "Enter the number of elements you want to insert : \n";
    cin >> n;
    vector <int> arr(n);
    cout<<"Enter the array : \n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is : \n";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}