class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        // Bucket array: index = frequency, value = list of numbers with that frequency
        // Size is nums.size() + 1 because the max frequency is the length of the array
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto& pair : m) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num); // Place number in its frequency bucket
        }
        
        vector<int> result;
        // Iterate backwards from the highest possible frequency
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result; // We found our top K elements!
                }
            }
        }
        
        return result;
    }
};