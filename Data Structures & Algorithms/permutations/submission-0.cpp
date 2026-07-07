class Solution {
public:
    vector<vector<int>> final;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(0, cur, nums);

        return final;
    }

    void dfs(int index, vector<int>& cur_path, vector<int>& nums){
        // base case:
        if(cur_path.size() == nums.size()){
            final.push_back(cur_path);
            return;
        }

        // the loop:
        for(int i = 0; i<nums.size(); i++){
            if(find(cur_path.begin(), cur_path.end(), nums[i]) == cur_path.end()){

            //action:
            cur_path.push_back(nums[i]);

            // recurse:
            dfs(i+1, cur_path, nums);

            // backtrack:
            cur_path.pop_back();
            }
            
        }

        // int i = 0;
        // while (true){
        //     if(i == index){
        //         cur_path.push_back(nums[i]);
        //     }
        //     dfs(i+1, cur_path, nums);
        // }
    }
};
