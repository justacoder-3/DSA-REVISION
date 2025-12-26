#include <bits/stdc++.h>
using namespace std;

int longestCharacterReplacement1 (vector<char> arr, int k) {
    int maxlen = 0;
    for (int i = 0; i < arr.size(); i++) {
        int hash[26] = {0};
        int maxf = 0;
        for (int j = i; j < arr.size(); j++) {
            hash[arr[j]-'A']++;
            maxf = max(maxf, hash[arr[j]-'A']);
            int changes = (j-i+1) - maxf;
            if (changes <= k) {
                maxlen = max(maxlen, j-i+1);
            }
            else {
                break;
            }
        }
    }
    return maxlen;
}

int longestCharacterReplacement2(string s, int k) {
    int l = 0;
    int r = 0;
    int maxf = 0;
    int maxlen = 0;
    int n = s.size();
    int hash[26] = {0};
    while (r < n) {
        hash[s[r]-'A']++;
        maxf = max(maxf, hash[s[r]-'A']);
        int changes = (r-l+1) - maxf;

        if (changes > k) {
            while (changes > k) {
                hash[s[l]-'A']--;
                for (int i = 0; i < 26; i++) {
                    maxf = max(maxf, hash[i]);
                }
                l++;
                changes = (r-l+1) - maxf;
            }
        }

        if (changes <= k) {
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
};
