// Step 1 (Topo sort) -> Creating a stack. Making a dfs call for o to n-1 numbers and then inserting those numbers to the stack according to the dfs call. DFS call keeps going on unless there is no adjacent numbers in the list.
// Step 2 -> Go to the sorce node. From the source node, calculate the distance to all other nodes and then store them in the distance array.

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort (int node, vector<int> visited, vector<pair<int, int>> adj[], stack<int> &st) {
    visited[node] = 1;

    for (auto it : adj[node]) {
        if (!visited[node]) {
            int v = it.first;
            topoSort (v, visited, adj, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathDAG (int n, int m, vector<int> edges[]) {
    vector<pair<int, int>> adj[n];

    for (int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(n, 0);
    stack<int> st;

    // topo sort
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            topoSort (i, vis, adj, st);
        }
    }

    // distance vector
    vector<int> dis;
    for (int i=0; i<n; i++) {
        dis[i] = 1e9;
    }
    dis[0] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if (dis[node] + wt < dis[v]) {
                dis[v] = dis[node] + wt;
            }
        }
    }

    return dis;
}

// note that this type of problem can be solved using certain algorithms like dijkstra etc. but they take more no of step leading to more time complexity. But dijkstra can be used when the graph is cyclic becoz at that time topo sort wont work.