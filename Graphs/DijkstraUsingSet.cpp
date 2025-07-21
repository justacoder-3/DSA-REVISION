#include <bits/stdc++.h>
using namespace std;

vector<int> DijkstraUsingSet (vector<vector<int>> adj[], int v, int s) {
    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);

    st.insert({0, s});
    dist[s] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int d = it.first;
        st.erase(it);

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (d + edgeWt < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = d + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}