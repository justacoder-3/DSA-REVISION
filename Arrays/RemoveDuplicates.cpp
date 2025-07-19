//Brute force approach
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

//Optimized approach
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int n,int arr[]){
  int i=0;
  for(int j=1;j<n;j++){
    if(arr[i]!=arr[j]){
      arr[i+1]=arr[j];
      i++;
    }
  }
  return i+1;
}

int main(){
  int n;
  cout << "Enter the number of elements you want to insert : \n";
  cin >> n;
  int arr[n];
  cout<<"Enter the array : \n";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int count=removeDuplicates(n,arr);
  cout<<"Array after removing duplicates are : \n";
  for(int i=0;i<count;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}

