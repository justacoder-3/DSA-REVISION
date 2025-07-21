#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component) {
    vis[node] = 1;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, component);
        }
    }
}

vector<vector<int>> Components(vector<vector<int>> &edges, int V) {
    //build adjacency list
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //finding connected components
    vector<vector<int>> components;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            vector<int> component;
            dfs(i, adj, vis, component);
            components.push_back(component);
        }
    }

    return components;
}





// just for practice

// int main () {
//     int n = 5;
//     vector<vector<int>> adj1(n, vector<int>(n, 0));
//     vector<vector<int>> edges = {{0,1}, {0,2}, {2,3}};

//     for (auto &edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         adj1[u][v] = 1;
//     }

//     int n = 5;
//     vector<vector<int>> adj2(n);
//     vector<vector<int>> edges = {{0,1}, {0,2}, {2,3}};

//     for (auto &edge: edges) {
//         int u = edge[0];
//         int v = edge[1];
//         adj2[u].push_back(v);
//         adj2[v].push_back(u);
//     }
// }

