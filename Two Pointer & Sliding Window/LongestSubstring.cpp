#include <bits/stdc++.h>
using namespace std;

// brute force
int longestSubstring1 (int arr[], int n) {
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        int hash[n] = {0};

        for (int j = i; j < n; j++) {
            if(hash[arr[j]] == 1) {
                break;
            }
            hash[arr[j]] = 1;
            int len = j-i+1;
            maxlen = max(len, maxlen);
        }
    }
    return maxlen;
}
// TC = O(n^2)
// SC = O(n)

// optimal 
int longestSubstring2 (int arr[], int n) {
    unordered_map<int, int> mpp;
    int left = 0; 
    int maxlen = 0;

    for (int right = 0; right < n; right++) {
        if (mpp.find(arr[right]) != mpp.end() && mpp[arr[right]] > left) {
            left = mpp[arr[right]] + 1;
        }

        mpp[arr[right]] = right;
        maxlen = max(maxlen, right-left+1);
    }
    return maxlen;
}
// TC = O(n)
// SC = O(n)