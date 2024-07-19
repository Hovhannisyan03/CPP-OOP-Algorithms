char solution(string s) 
{
    unordered_map<char,int> map;
    for(int i = 0; i < s.size(); ++i)
    {
        if(map.count(s[i]) == 0)
        {
            map.insert({s[i],1});
        }
        else
        {
            ++map[s[i]];
        }
    }
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(map[s[i]] == 1)
        {
            return s[i];
        }
    }
    return '_';
}
