class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> index_umap;
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            int num = target - nums[i];
            if(index_umap.count(num))
            {
                return {index_umap[num], i};
            }
            index_umap[nums[i]] = i;
        }
        return {};
    }
};