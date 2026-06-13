class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size()<2){
        return 0;
    }
    int curr, best = 0;

    for (int i = 0; i<prices.size()-1; i++ ){
        for (int j = i+1; j<prices.size(); j++){
            curr = prices[j] - prices[i];
            if (best < curr){
                best = curr;
            }
            // cout << best <<" " << curr << endl;
        }
    }

    return best;
        
    }
};
