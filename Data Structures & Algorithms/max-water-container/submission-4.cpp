class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        auto volume = [](int a, int b, vector<int> v){return (b-a)*min(v[b], v[a]);};
        int max_vol = volume(left, right, heights);

        while (left < right){
            if (heights[left] <= heights[right]){
                left++;
            }
            else {
                right--;
            }

            if (volume(left, right, heights) > max_vol){
                max_vol = volume(left, right, heights);
            }
        }
        return max_vol;

    }
};
