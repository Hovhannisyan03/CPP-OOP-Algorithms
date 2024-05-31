class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
        {
            return false;
        }

        long int after = 0;
        if(x > 0)
        {   
            int num = x;
            while(num != 0)
            {
                after = after * 10 + num % 10;
                num /= 10;
            }
        }    
        return after == x;

    }
};