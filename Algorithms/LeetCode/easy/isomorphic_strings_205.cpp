class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> s_antT;
        unordered_map<char,char> t_andS;
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            if(!s_antT.contains(s[i]))
            {
                if(t_andS.contains(t[i]))
                {
                    return false;
                }
                s_antT.insert({s[i],t[i]});
                t_andS.insert({t[i],s[i]});
            }
            else if(s_antT[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};
