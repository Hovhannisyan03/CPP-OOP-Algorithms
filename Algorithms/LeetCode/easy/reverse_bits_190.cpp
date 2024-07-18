class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        int count = 0;
        while(count < 32)
        {
            result = (result << 1) | (n & 1);
            n >>= 1;
            ++count;
        }    
        return result;
    }
};
