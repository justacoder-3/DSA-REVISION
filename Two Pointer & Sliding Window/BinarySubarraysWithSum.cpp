#include <bits/stdc++.h>
using namespace std;

int helperFunction (vector<int> arr, int k) {
    if (k < 0) {
        return 0;
    }

    int r = 0; 
    int l = 0;
    int count = 0;
    int n = arr.size();
    int sum = 0;

    while (r < n) {
        sum = sum + arr[r];

        while (sum > k) {
            sum = sum - arr[l];
            l++;
        }

        count = count + (r-l+1);
        r++;
    }

    return count;
}

int binarySubarray (vector<int> arr, int k) {
    return helperFunction(arr, k) - helperFunction(arr, k-1);
}

// TC - O(2*(n+n)) => O(2*2n) => O(n)
// SC - O(1)
