class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        sort(nums.begin(), nums.end()); // O(n log n)

        for (int i = 0; i < nums.size(); i++) {
            // Optimization 1: If the lowest number is > 0, sum can never be 0.
            if (nums[i] > 0) break; 
            
            // Optimization 2: Skip duplicate 'i' values
            if (i > 0 && nums[i] == nums[i - 1]) continue; 

            int left = i + 1; // Always start strictly to the right of i
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    final.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step both inward to keep searching
                    left++;
                    right--;

                    // Optimization 3: Skip duplicate 'left' values to avoid duplicate triplets
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    // Optimization 4: Skip duplicate 'right' values
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return final;
    }
};