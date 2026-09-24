class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =0;
        int sell = 0;
        int result = 0;
        while (sell < prices.size()){
            if (prices[sell] > prices[buy])
                result = max(result, prices[sell]-prices[buy]);
            else
                buy = sell;
            sell++;
        }
        return result;
    }
};
