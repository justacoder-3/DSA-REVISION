#include <bits/stdc++.h>
using namespace std;

int iterativeImplementation (vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (target > arr[mid]) {
            low = mid+1;
        }
        else {
            low = mid-1;
        }
    }
    return -1;
}

int recursiveImplementation (vector<int> &arr, int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = (low+high)/2;
    if (target == arr[mid]) {
        return mid;
    }
    else if (target > arr[mid]) {
        return recursiveImplementation (arr, mid+1, high, target);
    }
    return recursiveImplementation (arr, low, mid-1, target);
}

int requiredFunction (vector<int> arr, int target) {
    return recursiveImplementation (arr, 0, arr.size() - 1, target);
}

// Time complexity is O(log n) (base is 2)
// overflow case is to use mid = low + ([high-low]/2);