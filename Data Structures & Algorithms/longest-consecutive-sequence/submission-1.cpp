class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        if(nums.size() < 2){
            return nums.size();
        }

        int left = 0;
        int right = 1;

        int m = 1;
        int duplicates = 0;
        while(left < right && right < nums.size()){

            if (nums[right] - nums[right-1] == 0){
                duplicates++;
            }
            else if(nums[right] - nums[right-1] != 1){
                left = right;
                duplicates = 0;
            }
            m = max(m, right-left+1-duplicates);
            right++;
        }

        return m;
    }
};
