class Solution {
public:
    vector<vector<int>> final;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur_path;
        // Sorting is optional here, but helps if you want to optimize later!
        dfs(0, nums, cur_path, target);
        return final;
    }

    // Notice we pass target down, we don't need a separate sum!
    void dfs(int index, vector<int>& nums, vector<int>& cur_path, int target) {
        
        // BASE CASES
        if (target == 0) {
            final.push_back(cur_path);
            return;
        }
        if (target < 0) {
            return; // We busted!
        }

        // THE LOOP
        for (int i = index; i < nums.size(); i++) {
            
            // ACTION: Take the number
            cur_path.push_back(nums[i]);
            
            // RECURSE: Notice we pass 'i', NOT 'i + 1'! 
            // We also pass (target - nums[i]) to keep O(1) track of our sum.
            dfs(i, nums, cur_path, target - nums[i]);
            
            // BACKTRACK: Clean up
            cur_path.pop_back();
        }
    }
};
