class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // a slight optimization so we can sort out what the possibilities for the first element is
        vector<pair<int, int>> possible;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j] == word[0]){
                    possible.push_back({i, j});
                }
            }
        }
        for(auto p : possible){
            string temp = "";
            temp.push_back(word[0]);
            board[p.first][p.second] = '*'; // to mark visited (action)
            dfs(temp, {p.first, p.second}, board, word); //recurse
            board[p.first][p.second] = word[0]; //backtrack
        }

        return flag;
    }


    bool flag = false;


    void dfs(string& cur, pair<int, int> coord, vector<vector<char>>& board, string word){
        // base cases:
        if(cur == word || flag == true){
            flag = true;
            return;
        }
        if(cur.size() >= word.size()){
            return;
        }

        vector<pair<int, int>> coordinates {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // choices (with loop):
        for(auto pr : coordinates){
            if(coord.first + pr.first < board.size() && coord.second + pr.second < board[0].size() && coord.first + pr.first >= 0 && coord.second + pr.second >= 0){
                char temp = board[coord.first + pr.first][coord.second + pr.second];
                if (temp != '*'){
                    cur.push_back(temp); //action to try and form an answer
                    board[coord.first + pr.first][coord.second + pr.second] = '*'; //action to mark a visited guy
                }
                else continue;

                dfs(cur, {coord.first + pr.first, coord.second + pr.second}, board, word); // recurse

                cur.pop_back(); // backtrack 1.0
                board[coord.first + pr.first][coord.second + pr.second] = temp; // backtrack 2.0 (ofc backtracking has 2 steps here)

            }
        }


    }
};
