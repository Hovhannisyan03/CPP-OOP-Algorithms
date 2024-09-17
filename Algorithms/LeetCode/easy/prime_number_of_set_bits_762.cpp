class Solution {
public:
    int countPrimeSetBits(int left, int right) 
    {
        int count = 0;
        while(left <= right)
        {
            int current = left;
            int k = 0;
            while(current != 0)
            {
                k += current & 1;
                current >>= 1;
            }
            count += isPrime(k) ? 1 : 0;
            ++left;
        }
        return count;
    }
    bool isPrime(int num) 
    {
        if (num <= 1) 
        {
            return false;
        }
        if (num <= 3) 
        {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i <= num; i += 6) 
        {
            if (num % i == 0 || num % (i + 2) == 0) 
            {
                return false;
            }
        }
        return true;
    }
};
