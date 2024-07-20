vector<string> solution(vector<string> inputArray) 
{
    vector<string> result;
    int longest = 0;
    for(auto elem : inputArray)
    {
        if(longest < elem.size())
        {
            longest = elem.size();
        }
    }
    
    for(auto elem : inputArray)
    {
        if(longest == elem.size())
        {
            result.push_back(elem);
        }
    }
    return result;
}
