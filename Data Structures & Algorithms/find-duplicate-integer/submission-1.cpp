class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> table;
        for(int num : nums){
            if(table.find(num) != table.end()){
                return num;
            }
            else{
                table.insert(num);
            }
        }
    }
};
