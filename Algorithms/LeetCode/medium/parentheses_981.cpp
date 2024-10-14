class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> open;
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                open.push(s[i]);
            }
            else if(open.empty())
            {
                ++count;
            }
            else
            {
                open.pop();
            }
        }
        return open.size() + count;
    }
};
