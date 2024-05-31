class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int> str;
        for(int i = 0; i < list1.size(); ++i)
        {
            str.insert({list1[i],i});
        }    
        int sum = INT_MAX;
        vector<string> res;
        for(int i = 0; i < list2.size(); ++i)
        {
            if(str.contains(list2[i]))
            {
                int tmpSum = str[list2[i]] + i;
                if(sum == tmpSum)
                {
                    res.push_back(list2[i]);
                }
                else if(sum > tmpSum)
                {
                    sum = tmpSum;
                    res.clear();
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};