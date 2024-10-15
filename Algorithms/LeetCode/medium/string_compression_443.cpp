class Solution {
public:
    int compress(vector<char>& chars) 
    {   
        string result = "";
        for(int i = 0; i < chars.size(); ++i)
        {
            int count = 1;
            while(i < chars.size() - 1 && chars[i] == chars[i + 1])
            {
                ++i;
                ++count;
            }
            result += chars[i];
            if(count > 1)
            {
                result += to_string(count);
            }
        }
        
        for(int i = 0; i < result.size(); ++i)
        {
            chars[i] = result[i];
        }
        return result.size();
    }
};
