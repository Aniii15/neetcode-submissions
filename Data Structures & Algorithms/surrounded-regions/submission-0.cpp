class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // only care about the visited 'O's
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            for(int j : {0, cols -1}){
                if(board[i][j] == 'O') q.push({i, j});
            }
        }

        for(int j = 0; j < cols; j++){
            for(int i : {0, rows - 1}){
                if(board[i][j] == 'O') q.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){ // main bfs step!
            auto [r, c] = q.front();
            visited[r][c] = true;
            q.pop();
            for(auto dir : directions){
                int newR = r + dir.first;
                int newC = c + dir.second;

                if(newR < rows && newC < cols && newR >= 0 && newC >= 0 && 
                   board[newR][newC] == 'O' && !visited[newR][newC]){
                    q.push({newR, newC});
                }
            }
        }

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(!visited[r][c] && board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }

    }
};
