class Solution {
public:
    // Your exact custom comparator
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        // 1. Count frequencies (You already wrote this)
        for (int num : nums) {
            m[num]++;
        }
        
        // 2. The Missing Link: Dump the map into a vector
        vector<pair<int, int>> v(m.begin(), m.end());
        
        // 3. Sort the vector using your comparator!
        sort(v.begin(), v.end(), cmp);
        
        // 4. Extract the top K elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].first);
        }
        
        return result;
    }
};