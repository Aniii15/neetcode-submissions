// -----------How to Optimize to a 2-Pass Approach-------------
// While your 3-pass method is clever, interviewers will often ask: "Can we do this without the final scan at the end?"
// You can eliminate the third pass entirely by combining your very first BFS template (the one with lvlSize) with a simple counter variable.
// Here is the logic:
// Pass 1 (Pre-scan): While pushing the rotten oranges into the queue, also count exactly how many fresh oranges exist.
// Pass 2 (Level-by-Level BFS): Run your BFS. Every time you rot a fresh orange, decrement your fresh counter. Track the minutes by incrementing a time variable after every full level of the BFS completes.
// The Return: At the very end, just check: if (fresh == 0) return time; else return -1;
// Here is what that industry-standard 2-pass optimization looks like:

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0; // Track fresh oranges!

        // Pass 1: Enqueue rotten, count fresh
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2) q.push({r, c});
                else if(grid[r][c] == 1) freshCount++;
            } 
        }

        // Edge case: If there are no fresh oranges to begin with, time is 0
        if (freshCount == 0) return 0;

        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;

        // Pass 2: Level-Order BFS
        while(!q.empty()){
            int lvlSize = q.size(); // Process one full minute at a time
            bool rottedSomething = false;

            while(lvlSize--){
                auto [r, c] = q.front();
                q.pop();

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    // If it's a fresh orange...
                    if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 1){
                        grid[newR][newC] = 2; // Sink it (rot it)
                        freshCount--;         // Decrement our tracker
                        q.push({newR, newC});
                        rottedSomething = true;
                    }
                }
            }
            // Only increment time if we actually rotted something this minute
            if (rottedSomething) minutes++;
        }

        // Did we get them all?
        return freshCount == 0 ? minutes : -1;
    }
};
// Level-Order Mastery: Using lvlSize is the universal way to track "distance from source" when you aren't allowed to mutate the input array with distance integers.