class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int num : nums){
            table[num]++;
            if(table[num] > 1){
                return num;
            }
        }
    }
};
