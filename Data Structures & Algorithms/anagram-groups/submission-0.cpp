class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Our map: Key is the frequency string, Value is the list of anagrams
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string s : strs) {
            // 1. Create the 26-element frequency array (just like Valid Anagram!)
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // 2. Convert the frequency array into a string signature
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#"; 
                // The '#' is crucial to separate numbers (e.g., '1' and '11')
            }
            
            // 3. Group the original string under this unique key
            anagramGroups[key].push_back(s);
        }
        
        // 4. Extract just the groups (the values) to return
        vector<vector<string>> result;
        for (auto pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};