class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_vol = 0;
        for(int i = 0; i<heights.size()-1; i++){
            for(int j = i+1; j < heights.size(); j++){
                if((j-i)*min(heights[i], heights[j]) > max_vol){
                    max_vol = (j-i)*min(heights[i], heights[j]);
                }
            }
        }
        return max_vol;
    }
};
