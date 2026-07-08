class Solution {
public:
    vector<vector<int>> results;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur_path;

        dfs(0, cur_path, nums);

        return results;
        
    }

    void dfs(int index, vector<int>& cur_path, vector<int>& nums){
        // no if-block in the base case!
        results.push_back(cur_path);

        for(int i = index; i < nums.size(); i++){
            // if neighbors are twins, we don't care for the later twins' combos
            if(i > index && nums[i] == nums[i-1]) continue;

            // action:
            cur_path.push_back(nums[i]);

            // recurse:
            dfs(i+1, cur_path, nums);

            // backtrack:
            cur_path.pop_back();
        }

    }
};
