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
// Time: O(n^2)
// Space: O(1)

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
// Time: O(n)
// Space: O(n)

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
// Time: O(n)
// Space: O(1)
// overflow in large inputs is possible in this approach thats why we use xor approach


//xor approach
int missingNumber5 (int arr[], int n) {
    int xor1 = 0;
    int xor2 = 0;

    for (int i=0; i<=n; i++) {
        xor1 ^= i;
    }

    for (int i=0; i<n; i++) {
        xor2 ^= arr[i];
    }

    return xor1^xor2;
}
// Time: O(n)
// Space: O(1)
// Best balance: no extra space, no overflow

// best approach is xor approach due to its best time complexity and space complexity

