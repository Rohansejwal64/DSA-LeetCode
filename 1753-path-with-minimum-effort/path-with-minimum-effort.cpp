class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int r = heights.size();
    int c = heights[0].size();
    
    vector<vector<int>> result(r, vector<int>(c, INT_MAX)); // store min effort to reach each cell
    priority_queue< pair<int,pair<int,int>>, 
                    vector< pair<int,pair<int,int>>>, 
                    greater< pair<int,pair<int,int>>>> pq;
    
    result[0][0] = 0;
    pq.push({0, {0, 0}});
    
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    while (!pq.empty()) {
        auto temp = pq.top();
        int e = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        pq.pop();
        
        // Skip outdated state
        //if (e > result[x][y]) continue;
        
        if (x == r-1 && y == c-1) return e;
        
        for (vector<int> &d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                int ne = max(e, abs(heights[nx][ny] - heights[x][y])); // max so far
                if (ne < result[nx][ny]) {
                    result[nx][ny] = ne;
                    pq.push({ne, {nx, ny}});
                }
            }
        }
    }
    return -1;
}

};