class Solution {
public:
    int firstUniqChar(string s) 
    {
        int a = 0;//set all bits
        int b = 0;//set not uniques

        for(int i = 0; i < s.size(); ++i)
        {
            if(a & (1 << (s[i] - 'a')))
            {
                b |= 1 << (s[i] - 'a');
            }
            else
            {
                a |= 1 << (s[i] - 'a');
            }
        }
        
        for(int i = 0; i < s.size(); ++i)
        {
            if((b & (1 << (s[i] - 'a'))) == 0)
            {
                return i;
            }
        }
        return -1;
    }
};