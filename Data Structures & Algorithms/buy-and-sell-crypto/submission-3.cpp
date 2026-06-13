class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size()<2){
        return 0;
    }

    int curr, best = 0;

    int left = 0;
    for (int right = 1; right < prices.size(); right++){
        if (prices[right] > prices[left]){
            curr = prices[right] - prices[left];
            if (curr > best){
                best = curr;
            }
        }
        else{
            left = right;
        }

    }
    return best;
        
    }
};
