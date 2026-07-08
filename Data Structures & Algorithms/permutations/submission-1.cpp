// better solution:
class Solution {
public:
    vector<vector<int>> results;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flags (nums.size(), false);
        vector<int> cur_path;
        dfs(0, cur_path, flags, nums);

        return results;
    }

    void dfs(int index, vector<int>& cur_path, vector<bool>& flags, vector<int>& nums){
        if(cur_path.size() == nums.size()){
            results.push_back(cur_path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(flags[i] == false){
                cur_path.push_back(nums[i]);
                flags[i] = true;

                dfs(i+1, cur_path, flags, nums);

                cur_path.pop_back();
                flags[i] = false; // this is an easy to forget part of the backtrack
            }
        }

    }
};
