class Solution {
public:
    bool isPalindrome(string s) 
    {
        int f = 0;
        int l = s.size() - 1;
        while(f <= l)
        {
            if(!std::isalnum(s[f]))
            {
                ++f;
                continue;
            }

            if(!std::isalnum(s[l]))
            {
                --l;
                continue;
            }

            else if(std::tolower(s[f]) == std::tolower(s[l]))
            {
                ++f;
                --l;
            }
            else
            {
                return false;
            }
        }  
        return true;
    }
};
