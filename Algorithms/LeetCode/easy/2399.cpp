class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        unordered_map<char,int> map;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!map.contains(s[i]))
            {
                map.insert({s[i], i});
            }
            else
            {
                int distanceSum = i - map[s[i]] - 1;
                if(distance[s[i] - 'a'] != distanceSum)
                {
                    return false;
                }
            }
        }
        return true;
    }
};