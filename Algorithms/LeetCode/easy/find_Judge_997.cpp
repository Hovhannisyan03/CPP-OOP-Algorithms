class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(trust.size() == 0 && n == 1)
        {
            return n;
        }
        vector<int> in_degree(n + 1,0);
        for(int u = 0; u < trust.size(); ++u)
        {        
            ++in_degree[trust[u][1]];
        }   

        int result = -1;
        for(int i = 0; i < in_degree.size(); ++i)
        {
            if(n - 1 == in_degree[i])
            {
                result = i;
                for(int u = 0; u < trust.size(); ++u)
                {
                    if(trust[u][0] == i)
                    {
                        result = -1;
                        break;
                    }
                }
                break;
            }
        }
        return result;
    }
};
