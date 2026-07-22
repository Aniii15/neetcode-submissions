class Solution {
   public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        vector<pair<int, int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> q; // for our multi source bfs
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            auto coordinates = q.front();
            q.pop();
            for(auto& dir : directions){
                
                int newR = dir.first + coordinates.first;
                int newC = dir.second + coordinates.second;

                if(newR >= 0 && newC >= 0 && newR < grid.size() && newC < grid[0].size() && grid[newR][newC] == 2147483647){
                    grid[newR][newC] = grid[coordinates.first][coordinates.second] + 1;
                    q.push({newR, newC});
                }
            }
        }
    }
};
