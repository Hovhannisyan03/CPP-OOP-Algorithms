class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long count = 0;
        int size = s.size();
        long long result = 0;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(s[i] == '0')
            {
                ++count;
            }
            else
            {
                result += count;
            }
        } 
        
        return result;
    }
};
