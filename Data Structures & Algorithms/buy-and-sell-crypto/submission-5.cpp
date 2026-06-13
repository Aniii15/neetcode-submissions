class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() < 2){
            return 0;
        }

        int left = 0;
        int right = 0;

        int profit = 0;

        while(left <= right && right+1 < prices.size()){
            if(prices[left] > prices[right]){
                left = right;
            }
            right++;

            if(prices[right] - prices[left] > profit){
                profit = prices[right] - prices[left];
            }   
        }
        return profit;
    }
};
