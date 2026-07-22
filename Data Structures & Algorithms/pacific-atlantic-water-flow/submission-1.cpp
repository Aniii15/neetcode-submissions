// let's try multi source bfs for this one too!
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> final;

        vector<vector<bool>> pacific (rows, vector<bool> (cols, false));
        vector<vector<bool>> atlantic (rows, vector<bool> (cols, false));

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < rows; i++){ // left side (pacific)
            int j = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            pacific[i][j] = true;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && 
                       !pacific[newR][newC] && heights[r][c] <= heights[newR][newC]){
                        pacific[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }
        }

        for(int i = 0; i < rows; i++){ // right side (atlantic)
            int j = cols - 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            atlantic[i][j] = true;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && 
                       !atlantic[newR][newC] && heights[r][c] <= heights[newR][newC]){
                        atlantic[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }
        }

        for(int i = 0; i < cols; i++){ // top side (pacific)
            int j = 0;
            queue<pair<int, int>> q;
            q.push({j, i});
            pacific[j][i] = true;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && 
                       !pacific[newR][newC] && heights[r][c] <= heights[newR][newC]){
                        pacific[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }
        }

        for(int i = 0; i < cols; i++){ // bottom side (atlantic)
            int j = rows-1;
            queue<pair<int, int>> q;
            q.push({j, i});
            atlantic[j][i] = true;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(auto dir : directions){
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && 
                       !atlantic[newR][newC] && heights[r][c] <= heights[newR][newC]){
                        atlantic[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] == true && atlantic[i][j] == true) final.push_back({i, j});
            }
        }
        
        return final;
    }

};

