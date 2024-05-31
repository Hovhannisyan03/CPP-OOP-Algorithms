class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> check;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(check.find(nums[i]) == check.end())
            {
                check.insert({nums[i],i});
            }
            else
            {
                int sub = check[nums[i]] - i < 0 ? -1*(check[nums[i]] - i) : check[nums[i]] - i;
                if(sub <= k)
                {
                    return true;
                }
                else
                {
                    check[nums[i]] = i;
                }
            }
        } 
        return false;   
    }
};