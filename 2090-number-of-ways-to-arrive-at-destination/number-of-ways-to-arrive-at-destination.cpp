class Solution {
public:
int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n);
    for (vector<int> &edge : roads) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<vector<long long>> result(n, vector<long long>(2, 0)); 
    // result[i][0] = min dist to i
    // result[i][1] = ways to reach i

    for (int i = 0; i < n; i++) result[i][0] = LLONG_MAX;

    // priority_queue to ensure smallest distance first (like Dijkstra)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> q;

    result[0][0] = 0;  // dist to src
    result[0][1] = 1;  // 1 way to reach src
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d > result[u][0]) continue; // skip outdated entries

        for (auto &p : adj[u]) {
            int v = p.first;
            long long wt = p.second;
            long long newDist = d + wt;

            if (result[v][0] > newDist) {
                result[v][0] = newDist;
                result[v][1] = result[u][1];
                q.push({newDist, v});
            }
            else if (result[v][0] == newDist) {
                result[v][1] = (result[v][1] + result[u][1]) % MOD;
            }
        }
    }

    return (result[n-1][0] == LLONG_MAX) ? -1 : result[n-1][1];
}
};