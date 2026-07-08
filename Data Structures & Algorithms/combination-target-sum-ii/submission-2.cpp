// let's see how much we have to modify in combination sum I to solve this bad boy...
class Solution {
public:
    vector<vector<int>> results;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, temp, candidates);

        return results;
    }

    void dfs(int index, int target, vector<int>& cur_path, vector<int>& nums){
        // base cases:
        if (target == 0){
            results.push_back(cur_path);
            return;
        }
        if (target < 0){
            return;
        }

        // the loop:
        for(int i = index; i < nums.size(); i++){
            
            // holy-grail condition that eleminates duplicates from forming their own same combinations:
            if( i > index && nums[i] == nums[i-1]) continue;

            // action:
            cur_path.push_back(nums[i]);

            // recurse:
            dfs(i+1, target-nums[i], cur_path, nums);

            // backtrack:
            cur_path.pop_back();
        }



    }
};
