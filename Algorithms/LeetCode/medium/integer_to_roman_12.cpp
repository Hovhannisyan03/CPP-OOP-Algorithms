class Solution {
public:
    string intToRoman(int num) 
    {
        vector<int> key{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> value{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string roman = "";

        for(int i = value.size() - 1; i >= 0; --i)
        {
            while(num >= key[i])
            {
                roman += value[i];
                num -= key[i];
            }
        }
        return roman;
    }
};
