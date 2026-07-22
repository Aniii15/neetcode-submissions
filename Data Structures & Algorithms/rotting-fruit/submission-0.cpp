class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            } 
        }

        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [r, c] = q.front();
            
            q.pop();

            for(auto dir : directions){
                int newR = r + dir.first;
                int newC = c + dir.second;

                if(newR < rows && newC < cols && newR >= 0 && newC >= 0 && grid[newR][newC] == 1){
                    grid[newR][newC] = 1 + grid[r][c];
                    q.push({newR, newC});
                }
            }
        }
        int time = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] > 0){
                    if (grid[r][c] == 1) return -1;
                    time = max(time, grid[r][c] - 2);
                }
            }
        }
        return time;
    }
};
