#include <bits/stdc++.h>
using namespace std;

int MaxConsecutive1 (int arr[], int n) {
    int count = 0;
    int maxi = 0;

    for (int i=0; i<n; i++) {
        if (arr[i] == 1) {
            count++;
            maxi = max(count, maxi);
        }
        else {
            count = 0;
        } 
    }
    return maxi;
}