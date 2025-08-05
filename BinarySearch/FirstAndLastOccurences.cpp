#include <bits/stdc++.h>
using namespace std;

// brute force
pair<int, int> firstAndLastOccurence1 (vector<int> &arr, int x) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    return {first, last} ;
}
// time complexity = O(n) and space complexity is O(1)

// optimal solution (for who know about upper bound and lower bound) 
int lowerBound (vector<int> arr, int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int ans = n;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[mid] >= x) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int upperBound (vector<int> arr, int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int ans;
    while (low <= high) {
        int mid = low + ((high-low)/2);
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

pair<int, int> firstAndLastOccurence2 (vector<int> arr, int x, int n) {
    int lb = lowerBound(arr, x);
    int ub = upperBound(arr, x);
    if (lb == n || arr[lb] != x) {
        return {-1, -1};
    }
    return {lb, ub-1};
} 

// time complexity is O(log n) (base 2) and space complexity is O(1)

// optimal solution (if asked in binary search method) 
// but we need to search first ovcurence and last occurence separately
int firstOccurence (vector<int> arr, int x) {
    int n = arr.size();
    int high = n-1;
    int low = 0;
    int first = -1;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[mid] == x) {
            first = mid;
            high = mid-1;
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
            low = mid+1;
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

pair<int, int> firstAndLastOccurence3 (vector<int> arr, int x) {
    int last = lastOccurence (arr, x);
    int first = firstOccurence (arr, x);
    if (last == -1) {
        return {-1, -1};
    }
    return {first, last};
}