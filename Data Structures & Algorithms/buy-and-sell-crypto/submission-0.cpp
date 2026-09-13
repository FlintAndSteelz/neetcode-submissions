class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 0; i < prices.size();++i){
            for (int j = i +1; j < prices.size();++j){
                if (prices[j] - prices[i] >0)
                    result = max(result, prices[j]-prices[i]);
            }
        }
        return result;
    }
};
