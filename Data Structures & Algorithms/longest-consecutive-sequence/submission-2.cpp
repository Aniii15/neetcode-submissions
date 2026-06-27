class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Throw everything into a Hash Set to remove duplicates 
        // and enable O(1) lookups.
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Check if this number is the START of a sequence
            // (i.e., the number before it does not exist in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                
                int currentNum = num;
                int currentStreak = 1;

                // Count upwards as long as the next number exists
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update our maximum record
                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};