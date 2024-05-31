class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        size_t size = nums.size();
        int k = 1;
        for(size_t i = 1; i < size; ++i)
        {   
            if(nums[i - 1] != nums[i])
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};