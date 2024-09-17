class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int prev = -1;
        while(n != 0)
        {
            if((n & 1) == prev)
            {
                return false;
            }
            else
            {
                prev = n & 1;
            }
            n >>= 1;
        }
        return true;
    }
};
