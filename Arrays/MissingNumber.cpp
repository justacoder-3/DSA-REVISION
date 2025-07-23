#include <bits/stdc++.h>
using namespace std;

// brute force approach
int missingNumber1 (int arr[], int n) {
    for (int i=0; i<n; i++) {
        int flag = 0;
        for (int j=0; j<n; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            return i;
        }
    }
    return -1;
}

// hashing approach
int missingNumber2 (int arr[], int n) {
    int hash[n+1] = {0};

    for (int i=0; i<n; i++) {
        hash[arr[i]] = 1;
    }

    for (int i=0; i<=n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    return -1;
}

// sum approach
int missingNumber3 (int arr[], int n) {
    int sum1 = 0;
    for (int i=0; i<n; i++) {
        sum1 += arr[i];
    }

    int sum2 = 0;
    for (int i=0; i<=n; i++) {
        sum2 += i;
    }

    if (sum2 == sum1) {
        return -1;
    }

    return sum2 - sum1;
}

//xor approach
int missingNumber4 (int arr[], int n) {
    int xor1 = 0; // XOR of all elements from 0 to n
    int xor2 = 0; // XOR of all elements in array

    for (int i = 0; i <= n; i++) {
        xor1 ^= i;
    }

    for (int i = 0; i < n; i++) {
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;
}
