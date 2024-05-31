class Solution {
public:
    int findGCD(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        int min = nums[0];
        for(size_t i = 0; i < size; ++i)
        {
            if(max < nums[i])
            {
                max = nums[i];
            }
            if(min > nums[i])
            {
                min = nums[i];
            }
        }

        while(max != min)
        {
            if(max > min)
            {
                max -= min;
            }
            else 
            {
                min -= max;
            }
        }
        return max;
    }
};