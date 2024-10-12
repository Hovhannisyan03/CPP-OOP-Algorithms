class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result = "";
        string temp = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {   
            string current = strs[i];
            int j = 0;
            result = "";
            while(current[j] != '\0' && temp[j] != '\0')
            {
                if(temp[j] == current[j])
                {
                    result += temp[j];
                }
                else
                {
                    break;
                }
                ++j;
            }
            temp = result;
        }   
        return strs.size() == 1 ? strs[0] : result; 
    }
};
