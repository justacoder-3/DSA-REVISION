#include <bits/stdc++.h>
using namespace std;

// they will give us edges list, no of nodes, no of edges and the source node
vector<int> shortestPath (vector<vector<int>> &edges, int n, int m, int src) {
    vector<int> adj[n]; // adjacency list

    // making of adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    vector<int> dist(n, 1e9); // distance vector

    dist[src] = 0;
    queue<int> q; // queue
    q.push(src); 

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dist[node] + 1 < dist[it]) { // if distance of the current node with 1 added is less than the already present distance then update the distance or else let it be like that
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        } 
    }


    // updating the ans from distance vector which we calculated
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}


