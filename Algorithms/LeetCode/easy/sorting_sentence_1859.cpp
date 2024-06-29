class Solution {
public:
    string sortSentence(string s) 
    {
        string arr[9];
        for(int i = 0; i < s.size(); ++i)
        {
            string str = "";
            while(s[i] < '0' || s[i] > '9')
            {
                str += s[i];
                ++i;
            }
            arr['9' - s[i]] = str;
            ++i;
        }

        s = "";
        for(int i = 8; i >= 0; --i)
        {
            if(arr[i] != "")
            {
                s += arr[i];
            }

            if(i > 0 && arr[i - 1] != "")
            {
                s += " ";
            }
        }
        return s;
    }
};
