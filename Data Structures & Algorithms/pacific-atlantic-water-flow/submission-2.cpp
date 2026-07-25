class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        vector<vector<int>> finalRes;

        // Fire off DFS from all borders simultaneously 
        for (int r = 0; r < rows; r++) {
            dfs(heights, pac, r, 0);          // Left border (Pacific)
            dfs(heights, atl, r, cols - 1);   // Right border (Atlantic)
        }
        for (int c = 0; c < cols; c++) {
            dfs(heights, pac, 0, c);          // Top border (Pacific)
            dfs(heights, atl, rows - 1, c);   // Bottom border (Atlantic)
        }

        // Find the intersection
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                if (pac[i][j] && atl[i][j]) finalRes.push_back({i, j});
                
        return finalRes;
    }

private:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        for (auto dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            // Notice heights[newR][newC] >= heights[r][c] for the reverse flow
            if (newR >= 0 && newR < heights.size() && newC >= 0 && newC < heights[0].size() && 
                !visited[newR][newC] && heights[newR][newC] >= heights[r][c]) {
                dfs(heights, visited, newR, newC);
            }
        }
    }
};