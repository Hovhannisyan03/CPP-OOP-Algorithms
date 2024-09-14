class Solution {
public:
    int numTrees(int n) 
    {   
        std::vector<int> val(n + 1, -1);
        return helper(n,val);
    }

    int helper(int n, std::vector<int>& val)
    {
        if (n <= 1) 
        {
            return 1;
        }
        
        if (val[n] != -1) 
        {
            return val[n];
        }
        
        int count = 0;
        
        for (int i = 1; i <= n; ++i) 
        {
            int left = helper(i - 1, val);
            int right = helper(n - i, val);
            count += left * right;
        }
        
        val[n] = count;
        return count;
    }
};
