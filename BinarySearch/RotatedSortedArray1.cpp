#include <bits/stdc++.h>
using namespace std;

int rotatedSortedArray1 (vector<int> arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + ((high - low)/2);
        if (arr[mid] == target) {
            return mid; 
        }
        // if left is sorted
        else if (arr[low] <= arr[mid]) {
            // if target is in between low and mid
            if (arr[low] <= target && target < arr[mid]) {
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        // if right is sorted
        else {
            // if target is in between mid and high
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    // if you dont find the element return -1
    return -1;
}

// time complexity - O(log n) (base 2) (because its binary search)
// space complexity - O(1)