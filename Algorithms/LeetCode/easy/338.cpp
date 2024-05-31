class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> result;
        result.push_back(0);
        int i = 1;
        while(i <= n)
        {
            int count = 0;
            int num = i;
            while(num > 0)
            {
                count += num & 1;
                num >>= 1;
            }
            result.push_back(count);
            ++i;
        }  

        return result;  
    }
};