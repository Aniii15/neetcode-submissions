// the most optimal approach is multi-source BFS, its quite powerful and
// you were able to figure this out on your own! (the logic, not the code)
// 
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // This queue will hold the {row, col} coordinates of our cells
        queue<pair<int, int>> q;
        
        // Step 1: The Pre-Scan
        // Find every single treasure chest and put them in the queue first.
        // This is what makes it "Multi-Source". They all start at distance 0!
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        // We reuse your awesome direction array from the DFS problem!
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Step 2: The BFS Loop
        while (!q.empty()) {
            // Grab the cell at the front of the line and remove it
            pair<int, int> current = q.front();
            q.pop();
            
            int r = current.first;
            int c = current.second;
            
            // Step 3: Check all 4 neighbors
            for (auto pr : directions) {
                int nextRow = r + pr.first;
                int nextCol = c + pr.second;
                
                // BOUNDARY & INF CHECK: 
                // 1. Did we fall off the map?
                // 2. Is this neighbor actually an INF cell? (If it's -1 or 0, or already visited, we ignore it)
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] == 2147483647) {
                    
                    // Step 4: Update & Push
                    // The distance to this neighbor is exactly 1 step further than our current cell
                    grid[nextRow][nextCol] = grid[r][c] + 1;
                    
                    // Now push this newly discovered cell into the queue so it can spread to ITS neighbors later
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
};