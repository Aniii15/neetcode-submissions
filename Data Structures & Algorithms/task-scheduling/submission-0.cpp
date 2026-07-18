class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();

        // Step 1: Count frequencies using a hash map
        std::unordered_map<char, int> frequency_map;
        for (char c : tasks) {
            frequency_map[c]++;
        }

        // Step 2: Find the highest frequency value
        int max_frequency = 0;
        for (const auto& pair : frequency_map) {
            if (pair.second > max_frequency) {
                max_frequency = pair.second;
            }
        }

        // Step 3: Collect all elements that match the max frequency (handles ties)
        std::vector<char> most_frequent_elements;
        for (const auto& pair : frequency_map) {
            if (pair.second == max_frequency) {
                most_frequent_elements.push_back(pair.first);
            }
        }

        int comp = (max_frequency-1)*(n+1) + most_frequent_elements.size();

        return max(comp, sz);
    }
};
