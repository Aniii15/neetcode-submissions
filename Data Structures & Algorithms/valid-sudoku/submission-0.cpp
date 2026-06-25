class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<vector<int>>> table;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char num = board[i][j];
                if(num != '.'){
                    int k;
                    if (i>=0 && i<3){
                        if(j>=0 && j<3) k = 1;
                        if(j>=3 && j<6) k = 2;
                        if(j>=6 && j<9) k = 3;
                    }
                    if (i>=3 && i<6){
                        if(j>=0 && j<3) k = 4;
                        if(j>=3 && j<6) k = 5;
                        if(j>=6 && j<9) k = 6;
                    }
                    if (i>=6 && i<9){
                        if(j>=0 && j<3) k = 7;
                        if(j>=3 && j<6) k = 8;
                        if(j>=6 && j<9) k = 9;
                    }
                    table[num].push_back({i, j, k});

                    if(table[num].size() > 9) return false;
                }
            }
        }


        auto it = table.begin();
        while(it!= table.end()){
            auto vec = it->second;
            unordered_set<int> temp1;
            unordered_set<int> temp2;
            unordered_set<int> temp3;

            for(vector<int> v : vec){
                if(temp1.find(v[0]) != temp1.end()){
                    return false;
                }
                temp1.insert(v[0]);

                if(temp2.find(v[1]) != temp2.end()){
                    return false;
                }
                temp2.insert(v[1]);


                if(temp3.find(v[2]) != temp3.end()){
                    return false;
                }
                temp3.insert(v[2]);
            }
            it++;
        }

        return true;
    }
};
