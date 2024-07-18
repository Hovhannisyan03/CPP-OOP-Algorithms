class Solution {
public:
    int hammingWeight(int n) 
    {
        int count_of_bits = 0;
        while(n != 0)
        {
            if(n & 1)
            {
                ++count_of_bits;
            }
            n = n >> 1;
        }    
        return count_of_bits;
    }
};
