#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n,int arr[]){
    for(int i=1;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
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
    insertionSort(n,arr);
    cout<<"Elements of your array : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// void insertionSort (int n, vector <int> arr) {
//     for (int i = 1; i <= n-1; i++) {
//         int j = i;
//         while (j > 0 && arr[j-1] > arr[j]) {
//             int temp = arr[j-1];
//             arr[j-1] = arr[j];
//             arr[j] = temp;
//             j--;
//         }
//     }
// }