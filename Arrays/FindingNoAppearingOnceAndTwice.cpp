#include <bits/stdc++.h>
using namespace std;

// xor approach (optimal)
int NoAppearingOnce1 (int arr[], int n) {
    int xor1 = 0;
    for (int i=0; i<n; i++) {
        xor1 = xor1^arr[i];
    }
    return xor1;
}

// brute force approach
int NoAppearingOnce2 (int arr[], int n) {
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            return arr[i];
        }
    }
    return -1;
}

// using hash array approach
int Noappearing3 (int arr[], int n) {
    int maxval = *max_element(arr, arr+n);
    vector<int> hash(maxval+1, 0);

    for (int i=0; i<n; i++) {
        hash[arr[i]]++;
    }

    for (int i=0; i<=maxval; i++) {
        if (hash[i] == 1) {
            return i;
        }
    }

    return -1;
}

int main () {
    int n = 7;
    int arr[n] = {1, 1, 2, 3, 3, 4, 4};
    int x = NoAppearingOnce1 (arr, n);
    cout << x;
    int y = NoAppearingOnce2 (arr, n);
    cout << y;
}

