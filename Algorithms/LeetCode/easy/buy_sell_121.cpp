class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            min = min > prices[i] ? prices[i] : min;
            profit = profit > prices[i] - min ? profit : prices[i] - min;
        }
        return profit;
    }
};
