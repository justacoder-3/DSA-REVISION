#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraphFor0 (int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    queue<int> q;
    vector<int> bfs;
    vis[0] = 1;
    q.push(0);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

vector<int> bfsOfGraphForAll (int V, vector<int> adj[]) {
    queue<int> q;
    vector<int> vis(V, 0);
    vector<int> bfs;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node]) {
                    if(!vis[it]) {
                       vis[it] = 1;
                       q.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}