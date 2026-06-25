class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> final;
        int product = 1;

        int flag = 0;

        for (int& num : nums) {
            if (num != 0) {
                product *= num;
            } else {
                flag++;
            }
            if (flag > 1) {
                return vector<int>(nums.size(), 0);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (flag == 0) {
                final.push_back(product / nums[i]);
            } 
            else {
                if (nums[i] == 0) {
                    final.push_back(product);
                } 
                else {
                    final.push_back(0);
                }
            }
        }

        return final;
    }
};
