class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(t.size() < s.size())
        {
            return false;
        }

        int j = 0;
        for(int i = 0; i < t.size(); ++i)
        {
            if(s[j] == t[i])
            {
                ++j;
                if(j == s.size())
                {
                    break;
                }
            }
        }

        return j == s.size();
    }
};
