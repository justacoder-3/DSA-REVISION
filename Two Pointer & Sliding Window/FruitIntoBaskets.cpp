#include <bits/stdc++.h>
using namespace std;

int fruits1 (vector<int> arr, int k) {
    int n = arr.size();
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        set<int> st;
        for (int j = i; j < n; j++) {
            st.insert(arr[j]);
            if (st.size() <= 2) {
                maxlen = max(maxlen, j-i+1);
            }
            else {
                break;
            }
        }
    }
    return maxlen;
}

// TC - O(n^2)
// SC - O(3) -> constant

int fruits2 (vector<int> arr, int k) {
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int n = arr.size();
    unordered_map<int, int> mpp;

    while (r < n) {
        mpp[arr[r]]++;

        if (mpp.size() > k) {
            while (mpp.size() > k) {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }

        if (mpp.size() <= k) {
            int len = r-l+1;
            maxlen = max(maxlen, len);
        }
        r++;
    }
    return maxlen;   
}

// TC - O(n+n) = O(2n)
// SC - O(3) -> constant

int fruits3 (vector<int> arr, int k) {
    int r = 0;
    int l = 0;
    int maxlen = 0;
    int n = arr.size();
    unordered_map<int, int> mpp;

    while (r < n) {
        mpp[arr[r]]++;

        if (mpp.size() > k) {
            if (mpp[arr[r]] == 0) {
                mpp.erase(r);
            }
            l++;
        }

        if (mpp.size() <= k) {
            int len = r-l+1;
            maxlen = max(len, maxlen);
        }
        
        r++;
    }
    return maxlen;
} 
