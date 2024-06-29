class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> map;
        map.insert({nums[0],0});
        for(int i = 1; i < nums.size(); ++i)
        {
            if(map.contains(target - nums[i]))
            {
                return {map[target - nums[i]], i};
            }
            map.insert({nums[i],i});
        }
        return {};
    }
};
