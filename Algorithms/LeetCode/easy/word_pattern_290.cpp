class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char,string> char_and_word;
        unordered_map<string,char> word_and_char;
        int j = 0;
        int i = 0;
        for(i = 0; i < pattern.size(); ++i)
        {
            string word = "";
            if(j >= s.size())
            {
                break;
            }
            while (j < s.size() && s[j] != ' ') 
            {
                word += s[j++];
            }
            ++j;
            if(!char_and_word.contains(pattern[i]))
            {
                if(word_and_char.contains(word))
                {
                    return false;
                }
                char_and_word[pattern[i]] = word;
                word_and_char[word] = pattern[i];
            }
            else if(char_and_word[pattern[i]] != word)
            {
                return false;
            }
        }
        if(i == pattern.size() && j >= s.size())
        {
            return true;
        }
        return false;
    }
};
