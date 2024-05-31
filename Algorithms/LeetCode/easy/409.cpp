class Solution {
public:
    int longestPalindrome(string s) 
    {
        int arr[58] = {};
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            ++arr[s[i] - 'A'];
        }

        for(int i = 0; i < 58; ++i)
        {
            if(arr[i] % 2 != 0)
            {
                if((arr[i] == 1) && (count % 2 == 0))
                {
                    ++count;
                }
                else if(count % 2 == 0)
                {
                    count += arr[i];
                }
                else
                {
                    count += arr[i] - 1;
                }
            }
            else
            {
                count += arr[i];
            }
        }
        return count;
    }
};