#include <bits/stdc++.h>
using namespace std;

int Floor (vector<int> arr, int x) {
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int ans = -1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}

int Ceil (vector<int> arr, int x) {
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid-1;
        }

        else {
            low = mid+1;
        }
    }
    return ans;
}