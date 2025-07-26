#include <bits/stdc++.h>
using namespace std;

// complete brute force
int longestSubarray (int arr[], int n, int givenSum) {
    int len = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int sum = 0;
            for (int k=i; k<=j; k++) {
                sum = sum + arr[k];
            }
            if (sum == givenSum) {
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

// efficient brute force
int longestSubarray2 (int arr[], int n, int givenSum) {
    int len = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum = sum + arr[j];
            if (sum == givenSum) {
                len = max(len, j-i+1);
            }
        }
    }
}

// optimal approach
int longestSubArrayWithSumK (vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

// practice
int longSubarray4 (vector<int> a, long long k) {
    long long sum = 0;
    int maxLen = 0;
    map<long long, int> hashMap;

    for (int i=0; i<a.size(); i++) {
        sum += a[i];
        if (a[i] == k) {
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum-k;
        if (hashMap.find(rem) != hashMap.end()) {
            int len = i - hashMap[rem];
            maxLen = max(maxLen, len);
        }

        if (hashMap.find(sum) == hashMap.end()) {
            hashMap[sum] = i;
        }
    }
    return maxLen; 
}
