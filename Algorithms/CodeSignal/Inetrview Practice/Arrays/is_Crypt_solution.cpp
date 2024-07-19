bool solution(vector<string> crypt, vector<vector<char>> solution) 
{
    unordered_map<char,int> map;
    for(int i = 0; i < solution.size(); ++i)
    {
        map.insert({solution[i][0],solution[i][1] - '0'});
    }
    
    auto convertToInteger = [&](const string& str) -> int
    {
        int num = 0;
        if(map[str[0]] == 0 && str.size() > 1)
        {
            return -1;
        }
        
        for(auto elem : str)
        {
            num = num * 10 + map[elem];
        }
        return num;
    };
    
    int num1 = convertToInteger(crypt[0]);
    int num2 = convertToInteger(crypt[1]);
    int result = convertToInteger(crypt[2]);

    return num1 + num2 == result ? true : false;
}
