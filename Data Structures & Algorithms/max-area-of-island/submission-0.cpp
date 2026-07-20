class Solution {
private:
    vector<pair<int, int>> direction {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};


public:
    void dfs(pair<int, int> index, vector<vector<int>>& grid, int& islandSize){
        if(grid[index.first][index.second] == 0) return; // base case

        islandSize++;
        grid[index.first][index.second] = 0;

        for(auto pr : direction){
            int x = index.first + pr.first;
            int y = index.second + pr.second;

            if (x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0){
                pair<int, int> temp {x, y};
                dfs(temp, grid, islandSize);
            }
        }

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;

        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                int islandSize = 0;
                if(grid[i][j] == 1) dfs({i, j}, grid, islandSize);
                maxSize = max(islandSize, maxSize);
            }
        }
        return maxSize;
    }
};
