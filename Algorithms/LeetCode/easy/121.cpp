class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        int min = prices[0];
        int max = 0;
        for(int i = 1; i < size; ++i)
        {
            min = min > prices[i] ? prices[i] : min;
            max = max > prices[i] - min ? max : prices[i] - min;
        }
        return max;
    }
};