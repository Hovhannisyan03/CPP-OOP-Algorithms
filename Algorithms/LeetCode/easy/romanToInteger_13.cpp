class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> map;
        map.insert({'I',1});
        map.insert({'V',5});
        map.insert({'X',10});
        map.insert({'L',50});
        map.insert({'C',100});
        map.insert({'D',500});
        map.insert({'M',1000});

        int sum = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(map[s[i]] >= map[s[i + 1]])
            {
                sum += map[s[i]];
            }
            else
            {
                sum -= map[s[i]];
            }
        }

        return sum;

    }
};
