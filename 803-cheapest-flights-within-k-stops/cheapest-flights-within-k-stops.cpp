class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto &edge : flights) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }
    
    // Min-heap: {cost, node, stops}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, src, 0});
    
    // cost[node][stops] = min cost to reach node with exactly stops
    vector<vector<int>> cost(n, vector<int>(k+2, INT_MAX));
    cost[src][0] = 0;
    
    while (!pq.empty()) {
        auto [currCost, u, stops] = pq.top();
        pq.pop();
        
        if (u == dst) return currCost;
        if (stops > k) continue;
        
        for (auto &[v, w] : adj[u]) {
            int newCost = currCost + w;
            if (newCost < cost[v][stops+1]) {
                cost[v][stops+1] = newCost;
                pq.push({newCost, v, stops+1});
            }
        }
    }
    return -1;
}

};