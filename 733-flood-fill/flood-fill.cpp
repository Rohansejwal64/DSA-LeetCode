class Solution {
public:
vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

bool safe(int row, int col, int r , int c) {
    return row >= 0 && row < r && col >= 0 && col < c;
}

void dfs(vector<vector<int>>& image, int sr, int sc, int color, int initial) {
    int r = image.size();
    int c = image[0].size();
    for (auto &d : directions) {
        int newr = sr + d[0];
        int newc = sc + d[1];
        if (safe(newr, newc, r, c) && image[newr][newc] == initial) {
            image[newr][newc] = color;
            dfs(image, newr, newc, color, initial);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initial = image[sr][sc];
    if (initial == color) return image; // avoid infinite recursion
    image[sr][sc] = color;
    dfs(image, sr, sc, color, initial);
    return image;
}

};