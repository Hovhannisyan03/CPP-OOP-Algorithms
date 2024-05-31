class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t size_w1 = word1.length();
        size_t size_w2 = word2.length();
        string sum = "";
        int i = 0;
        int j = 0;
        int min_size = size_w1 > size_w2 ? size_w2 : size_w1;
        while(min_size != 0)
        {
            sum += word1[i];
            sum += word2[j];
            ++i;
            ++j;
            --min_size;
        }
        if(size_w1 > size_w2)
        {
            for(int k = i; k < size_w1; ++k)
            {
                sum += word1[k];
            }
        }
        else
        {
            for(int k = j; k < size_w2; ++k)
            {
                sum += word2[k];
            }
        }
        return sum;
    }
};