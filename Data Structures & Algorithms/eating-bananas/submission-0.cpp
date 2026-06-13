class Solution {
public:
int minEatingSpeed(vector<int>& piles, int h) {
    
    int min = 1;
    int max = *max_element(piles.begin(), piles.end());
    int ans = max;

    while (max > min)
    {
        int mid = (min + max) / 2;
        int sum = 0;
        for (double ele : piles)
        {
            ele = ceil(ele / mid);
            sum += ele;
        }
        if (sum <= h)
        {
            ans = mid;
            max = mid;
        }
        else
        {
            min = mid + 1;
        }
    }

    return ans;        
}
};
