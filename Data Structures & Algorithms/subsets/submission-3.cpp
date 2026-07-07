class Solution {
public:
    vector<vector<int>> results;
    void dfs(int index, vector<int>& current_path, vector<int>& nums){
        // base case:
        // every path is valid in this N-ary Tree!!
        results.push_back(current_path);

        // the choices:
        for (int i = index; i<nums.size(); i++){
            // action
            current_path.push_back(nums[i]);
            // recurse
            dfs(i+1, current_path, nums);
            // backtrack
            current_path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_path;
        dfs(0, cur_path, nums);

        return results;
    }
};
