// topo sort using bfs

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> kahnAlgo (int V, vector<int> adj[]) {
//     int indegree[] = {0};
//     queue<int> q;
//     vector<int> topo;

//     for (int i = 0; i < V; i++) {
//         for (auto it : adj[i]) {
//             indegree[i]++;
//         }
//     }

//     for (int i = 0; i < V; i++) {
//         if (indegree[i] == 0) {
//             q.push(i);
//         }
//     }

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         topo.push_back(node);

//         for (auto it : adj[node]) {
//             indegree[it]--;
//             if (indegree[it] == 0) {
//                 q.push(it);
//             }
//         }
//     }

//     return topo;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> kahnAlgo (int V, vector<int> adj[]) {
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

    return topo;
}