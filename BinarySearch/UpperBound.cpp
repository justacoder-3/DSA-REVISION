#include <bits/stdc++.h>
using namespace std;

int upperBound (vector<int> arr, int x) {
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid-1;
            
        }
        else {
           low = mid+1; 
        }
    }
    return ans;
}

// can be used for coding rounds ->
int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

// time complexity is similar to binary search that is O(log n) (base 2) and n is the size of an array