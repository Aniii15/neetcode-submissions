class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix (nums.size(), 1);
        vector<int> suffix (nums.size(), 1);

        for(int i = 0; i<nums.size()-1; i++){
            prefix[i+1] = prefix[i]*nums[i];
        }

        for(int j = nums.size()- 1; j>0; j--){
            suffix[j-1] = suffix[j]*nums[j];
        }

        vector<int> final;

        for(int k = 0; k<nums.size(); k++){
            final.push_back(prefix[k]*suffix[k]);
        }

        return final;
    }

};
