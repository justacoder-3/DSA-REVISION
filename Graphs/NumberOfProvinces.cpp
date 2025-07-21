#include <bits/stdc++.h>
using namespace std;

// converting matrix to list and then solving it 
void dfs (int node, vector<int> adjLs[], vector<int> &vis) {
    vis[node] = 1;

    for (auto it : adjLs[node]) {
        if (!vis[it]) {
            dfs(it, adjLs, vis);
        }
    }
}

int noOfProvinces (vector<vector<int>> adj, int V) {
    vector<int> adjLs[V];

    // code for converting adjacency matrix to adjacency list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int count = 0;
    vector<int> vis(V,0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adjLs, vis);
        }
    }

    return count;
}

// directly solving by using the matrix
void dfs2 (int node, vector<vector<int>> &adj, vector<int> &vis, int V) {
    vis[node] = 1;

    for (int j = 0; j < V; j++) {
        if (adj[node][j] == 1 && !vis[j]) {
            dfs2(j, adj, vis, V);
        }
    }
}

int noOfProvinces2 (vector<vector<int>> adj, int V) {
    vector<int> vis(V,0);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            dfs2(i, adj, vis, V);
        }
    }
    return count;
}