// brute-force O((m*n)^2):

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> final;

    
        for (int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // create a fresh visited matrix for every cell!
                pair <bool, bool> pr {false, false};
                dfs(r, c, heights, pr, visited);
                if (pr.first == true && pr.second == true){
                    final.push_back({r, c});
                }
            }
        }
        return final;
        
    }

    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& heights, pair<bool, bool>& pr, vector<vector<bool>>& visited){
        if(pr.first && pr.second) return; // for speed (early termination)
        visited[r][c] = true;
        if(r == 0 || c == 0) pr.first = true;
        if(r == heights.size()-1 || c == heights[0].size()-1) pr.second = true;
        for(auto& dir : directions){
            int newR = r + dir.first;
            int newC = c + dir.second;

            if(newR < heights.size() && newR >= 0 && newC < heights[0].size() && newC >= 0 && heights[newR][newC] <= heights[r][c] && visited[newR][newC] == false){
                dfs(newR, newC, heights, pr, visited);
            }
        }
    }
};
