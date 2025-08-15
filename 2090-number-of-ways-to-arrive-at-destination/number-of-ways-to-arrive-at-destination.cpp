class Solution {
public:
   #include <vector>
#include <queue>
#include <climits>


int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (vector<int>& edge : roads) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<int> pathCount(n, 0);
    dist[0] = 0;
    pathCount[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) {
            continue; // Skip if this is not the shortest distance to u
        }

        for (auto& [v, wt] : adj[u]) {
            if (dist[v] > currentDist + wt) {
                dist[v] = currentDist + wt;
                pathCount[v] = pathCount[u];
                pq.push({dist[v], v});
            } else if (dist[v] == currentDist + wt) {
                pathCount[v] = (pathCount[v] + pathCount[u]) % MOD;
            }
        }
    }

    return (dist[n - 1] == LLONG_MAX) ? -1 : pathCount[n - 1];
}
};