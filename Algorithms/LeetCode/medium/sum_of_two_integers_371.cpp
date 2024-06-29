class Solution {
public:
    int getSum(int a, int b) 
    {
        int res = 0;
        int carry = 0;

        for (int i = 0; i < 8 * sizeof(int); ++i) 
        {
            int bit_a = (a >> i) & 1;  
            int bit_b = (b >> i) & 1;  

            res |= ((bit_a ^ bit_b ^ carry) << i);

            carry = (bit_a & bit_b) ^ (bit_a & carry) ^ (bit_b & carry);
        }

        return res;
    }
};
