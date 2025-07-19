// This is classic Dijkstra Algo using Priority Queue
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra (vector<vector<int>> adj[], int v, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(v, 1e9);

    distance[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int edgeWt = it[1];
            int adjNode = it[0];

            if (d + edgeWt < distance[adjNode]) {
                distance[adjNode] = d + edgeWt;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}

// practice

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> dijkstra (vector<vector<int>> adj[], int v, int s) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     vector<int> distance(v, 1e9);

//     distance[s] = 0;
//     pq.push({0, s});

//     while (!pq.empty()) {
//         int node = pq.top().second;
//         int dis = pq.top().first;
//         pq.pop();

//         for (auto it : adj[node]) {
//             int edgeWt = it[1];
//             int adjNode = it[0];

//             if (dis + edgeWt < distance[adjNode]) {
//                 distance[adjNode] = dis + edgeWt;
//                 pq.push({distance[adjNode], adjNode});
//             }
//         }
//     }

//     return distance;
// }

