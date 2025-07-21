#include <bits/stdc++.h>
using namespace std;

vector<int> courseSchedule (int V, int m, vector<pair<int, int>> &prerequisites) {
    vector<int> adj[V];
    for (auto it : prerequisites) {
        adj[it.first].push_back(it.second);
    }

    queue<int> q;
    int indegree[V] = {0};
    vector<int> topo;

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    if (topo.size() == V) {
        return topo;
    }

    return {};
}

