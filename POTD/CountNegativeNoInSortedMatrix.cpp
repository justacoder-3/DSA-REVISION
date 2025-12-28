#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int result = 0;

    for (auto &vec : grid) {
        int idx = upper_bound(begin(vec), end(vec), 0, greater<int>()) - begin(vec);
        result += n - idx;
    }

    return result;
};
