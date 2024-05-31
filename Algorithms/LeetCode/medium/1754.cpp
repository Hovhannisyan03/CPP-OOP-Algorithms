class Solution {
public:
    string largestMerge(string word1, string word2)
    {
        int s1 = word1.size() - 1;
        int s2 = word2.size() - 1;
        int i = 0;
        int j = 0;    

        string result = "";
        while(i <= s1 && j <= s2)
        {
            if(word1[i] > word2[j])
            {
                result += word1[i++];
            }
            else if(word1[i] == word2[j])
            {
                int tmp1 = i + 1;
                int tmp2 = j + 1;
                while(word1[tmp1] == word2[tmp2] && (tmp1 <= s1 - 1 || tmp2 <= s2 - 1))
                {
                    ++tmp1;
                    ++tmp2;
                }

                if(word2[tmp2] > word1[tmp1])
                {
                    swap(word1, word2);
                    swap(s1,s2);
                    swap(i,j);
                }
                
                result += word1[i++];
            }
            else
            {
                result += word2[j++];
            }
        }

        while(i <= s1)
        {
            result += word1[i++];
        }

        while(j <= s2)
        {
            result += word2[j++];
        }

        return result;
    }
};  