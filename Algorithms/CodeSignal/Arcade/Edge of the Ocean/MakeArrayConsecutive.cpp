int solution(std::vector<int> statues) 
{
    int max = statues[0];
    int min = statues[0];
    for(int i = 1; i < statues.size(); ++i)
    {
        if(max < statues[i])
        {
            max = statues[i];
        }
        if(min > statues[i])
        {
            min = statues[i];
        }
    }   
    int arr[10] = {};
    for(int i = 0; i < statues.size(); ++i)
    {
        ++arr[statues[i]];
    }
    int count = 0;
    for(int i = min; i < max + 1; ++i)
    {
        if(arr[i] == 0)
        {
            ++count;
        }
    }
    return count;
}
