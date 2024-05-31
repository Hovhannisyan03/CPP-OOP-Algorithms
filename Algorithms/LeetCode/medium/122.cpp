class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int profit = 0;
        int i = 0;
        while(i != size - 1)
        {
            profit += prices[i] < prices[i + 1] ? prices[i + 1] - prices[i] : 0;
            ++i;
        } 
        return profit;
    }
};