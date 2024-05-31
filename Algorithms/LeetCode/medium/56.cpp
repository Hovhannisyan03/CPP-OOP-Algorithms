class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {        
        int size = intervals.size();
        for(int i = 1; i < size; ++i)
        {
            int next = intervals[i][0];
            int next2 = intervals[i][1];
            int loc = i;
            while((loc > 0) && (intervals[loc - 1][0] > next))
            {
                intervals[loc][0] = intervals[loc - 1][0];
                intervals[loc][1] = intervals[loc - 1][1];
                --loc;
            }
            intervals[loc][0] = next;
            intervals[loc][1] = next2;
        }

        vector<vector<int>> result(size,vector<int>(2));
        result[0][0] = intervals[0][0];
        result[0][1] = intervals[0][1];
        int j = 0;
        for(int i = 1; i < size; ++i)
        {
            if(result[j][1] >= intervals[i][0]  && result[j][1] <= intervals[i][1])
            {
                result[j][1] = intervals[i][1];
            }
            else if(result[j][1] >= intervals[i][0] && result[j][1] >= intervals[i][1])
            {
                continue;
            }
            else
            {
                ++j;
                result[j][0] = intervals[i][0];
                result[j][1] = intervals[i][1];
            }
        }
        if(size > j)
        {
            result.resize(j + 1,vector<int>(2));
        }

        return result;
    }
};  