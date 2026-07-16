class Solution {
public:
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        string temp = "";
        dfs(0, temp, digits);

        return ans;
    }

    void dfs(int index, string& cur_path, string& digits){
        if(cur_path.size() == digits.size()){
            ans.push_back(cur_path);
            return;
        }
        unordered_map<int, vector<char>> table {{2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};

        int num = digits[index] - '0';
        vector<char> possible = table[num];

        for (char c : possible){
            cur_path.push_back(c);

            dfs(index + 1, cur_path, digits);

            cur_path.pop_back();
        }
    }
};
