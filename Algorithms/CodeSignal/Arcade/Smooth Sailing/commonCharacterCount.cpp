int solution(string s1, string s2) 
{
    unordered_map<char,int> map;
    int count = 0;
    for(auto elem : s1)
    {
        if(!map.count(elem))
        {
            map.insert({elem,1});
        }
        else
        {
            ++map[elem];
        }
    }
    
    for(auto elem : s2)
    {
        if(map[elem] > 0)
        {
            ++count;
            --map[elem];
        }
    }
    return count;
}
