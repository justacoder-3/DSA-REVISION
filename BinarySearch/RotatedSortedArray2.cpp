// tell whether a target element is present or not in the given array which might contain duplicate elements also
#include <bits/stdc++.h>
using namespace std;

bool rotatedSortedArray2 (vector<int> arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + ((high - low)/2);
        if (arr[mid] == target) {
            return true;
        }
        // this is the extra part, consider the array [3, 1, 2, 3, 3, 3, 3] -> here low = mid = high
        else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low+1;
            high = high-1;
        }
        else if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }  
    }
    return 0;
}

// in this everything is similar to roatatedSortedArray2 but the only extra condition to check is (arr[low] == arr[mid] && arr[mid] == arr[high]), thats it.
// time complxity - O(log n) (base 2)
// space complexity - O(1)