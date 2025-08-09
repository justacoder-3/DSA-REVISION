#include <bits/stdc++.h>
using namespace std;

// duplicates can or cannot be present in an array
int NoOfRotations (vector<int> arr) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int index;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if (arr[low] < arr[high]) {
            index = low;
            break;
        }
        if (arr[low] <= arr[mid]) {
            index = low;
            low = mid + 1;
        }
        else {
            index = mid;
            high = mid - 1;
        }
    }
    return index;
} 

// time complexity - O(log n) (base 2) (with no/less duplicates)
// time complexity - O(n) (with many/complete duplicates)
// space complexity - O(1)