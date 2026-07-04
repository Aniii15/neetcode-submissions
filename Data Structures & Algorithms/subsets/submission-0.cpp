class Solution {
public:
    vector<vector<int>> final;
    void dfs(int idx, vector<int>& nums, vector<int> v){

        // base case:
        if(idx == nums.size()){
            final.push_back(v);
            return;
        }

        // other case (building up v):

        // "take":
        v.push_back(nums[idx]);
        dfs(idx+1, nums, v);
        v.pop_back();

        // "not take/ leave":
        dfs(idx+1, nums, v);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums, {});

        return final;
    }
};
