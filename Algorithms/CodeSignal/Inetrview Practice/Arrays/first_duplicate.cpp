int solution(vector<int> a) 
{
    unordered_map<int,int> map;
    int min = INT_MAX;
    int minIndex = INT_MAX;
    for(int i = 0; i < a.size(); ++i)
    {
        if(map.count(a[i]) == 0)
        {
            map.insert({a[i],i});
        }
        else
        {
            int currentSecondIndex = i;
            
            if (currentSecondIndex < minIndex)
            {
                minIndex = currentSecondIndex;
                min = a[i];
            }
        }
    }
    return min == INT_MAX ? -1 : min;
}
