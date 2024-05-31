class Solution {
public:
    bool isValid(string s) 
    {   
        if(s.length() % 2 != 0)
        {
            return false;
        }
        stack<char> str;
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            if(s[i] =='(' || s[i] == '{' || s[i] == '[')
            {
                str.push(s[i]);
            }
            else if(!str.empty())
            {
                if((s[i] == ')' && str.top() == '(') || (s[i] == '}' && str.top() == '{') || (s[i] == ']' && str.top() == '['))
                {
                    str.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    return str.empty();
    }
};