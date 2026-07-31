class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> heights (ROWS, vector<int> (COLS, 1e9));
        heights[0][0] = grid[0][0];
        
        // for every v in minHeap, v[0] =  max_h_on_that_path, v[1] = x, v[2] = y
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({heights[0][0], 0 , 0});

        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}};

        while(!minHeap.empty()){
            const auto vec = minHeap.top();
            int maxH = vec[0];
            int r = vec[1];
            int c = vec[2];
            minHeap.pop();
            if(r == ROWS-1 && c == COLS-1){
                return maxH;
            }

            for(const auto& dir : directions){
                int newR = dir.first + r;
                int newC = dir.second + c;

                if(newR < ROWS && newC < COLS && newR >= 0 && newC >= 0){
                    int newMaxH = max(maxH, grid[newR][newC]);
                    if(newMaxH < heights[newR][newC]){
                        heights[newR][newC] = newMaxH;
                        minHeap.push({newMaxH, newR, newC});
                    }
                }
            }

        }
        return -1;
    }
};
