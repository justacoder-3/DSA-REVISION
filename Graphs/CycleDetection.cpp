#include <bits/stdc++.h>
using namespace std;

bool cycleDetection (int V, vector<int> adj[]) {
    queue<int> q;
    int indegree[V] = {0};

    for (int i = 0; i<V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i<V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    if (count == V) {
        return false;
    }
    
    return true;
}