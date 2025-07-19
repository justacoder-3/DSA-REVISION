#include <bits/stdc++.h>
using namespace std;

bool linearSearch (vector <int> arr, int num) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            return true;
            break;
        }
    }
    return false;
}

int main () {
    int n, num;
    cout<<"Enter the number of elements : \n";
    cin>>n;
    vector <int> arr(n);
    cout<<"Enter the elements of array : \n";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int numberReq = linearSearch(arr, 4);
    cout << numberReq;
    return 0;
}