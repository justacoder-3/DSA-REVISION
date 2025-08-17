#include <bits/stdc++.h>
using namespace std;

// brute force approach 1
int frequencyCountMethod (vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
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

// time complexity = O(n^2)
// space complexity = O(1)

// optimal solution
int findingTheSingleElements (vector<int> arr) {
    int n = arr.size();

    if (n == 1) {
        return arr[0];
    }

    if (arr[0] != arr[1]) {
        return arr[0];
    }

    if (arr[n-1] != arr[n-2]) {
        return arr[n-1];
    }

    int low = 1;
    int high = n-2;

    while (low <= high) {
        int mid = low + ((high-low)/2);

        if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) {
            return arr[mid];
        }

        if((mid%2 == 1 && arr[mid-1] == arr[mid]) || (mid%2 == 0 && arr[mid+1] == arr[mid])) {
            low = mid+1;
        }

        else {
            high = mid-1;
        }
    }
    return -1;
}