#include <bits/stdc++.h>
using namespace std;

void dfs (int row, int col, vector<vector<int>> &ans, const vector<vector<int>> &image, int delrow[], int delcol[], int iniColor, int newColor) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, delrow, delcol, iniColor, newColor);
        }
    }
}

vector<vector<int>> floodFillAlgorithm (vector<vector<int>> &image, int sr, int sc, int newColor) {
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1}; 
    
    dfs (sr, sc, ans, image, delrow, delcol, iniColor, newColor);
    return ans;
}

// practice code

void dfs (int row, int col, int delrow[], int delcol[], const vector<vector<int>> &image, vector<vector<int>> &ans, int iniColor, int newColor) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i<4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol] == iniColor && image[nrow][ncol] != newColor) {
            dfs (nrow, ncol, delrow, delcol, image, ans, iniColor, newColor);
        }
    }
    

}

vector<vector<int>> floodFillAlgo (vector<vector<int>> &image, int srow, int scol, int newColor) {
    vector<vector<int>> ans = image;
    int iniColor = image[srow][scol];
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    dfs (srow, scol, delrow, delcol, image, ans, iniColor, newColor);
    return ans;
}