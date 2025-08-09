// minimum in rotated sorted array
#include <bits/stdc++.h>
using namespace std;

int minInRotatedSortedArray (vector<int> arr) {
    int n = arr.size();
    int ans = INT_MAX;
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        else if (arr[low] <= arr[mid]) {
            ans = min (ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min (ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// time complexity - O(log n) (base 2)
// space complexity - O(1)