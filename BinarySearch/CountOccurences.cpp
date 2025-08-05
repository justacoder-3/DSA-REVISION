#include <bits/stdc++.h>
using namespace std;

int firstOccurence (vector<int> arr, int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int first = -1;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence (vector<int> arr, int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int last = -1;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

pair<int ,int> countOccurences (vector<int> arr, int x) {
    int lo = lastOccurence(arr, x);
    int fo = firstOccurence(arr, x);
    if (fo == -1) {
        return {-1, -1};
    }
    return {fo, lo};
}

// time complexity is O(log n) (base 2)
// space complexity is O(1)