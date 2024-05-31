class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {   
        int size = nums.size(); 
        if(size == 1)
        {
            return 0;
        }
        int left = 0;
        for(size_t i = 0; i < size; ++i)
        {
            int j = i + 1;
            int right = 0;
            while(j < size)
            {
                right += nums[j];
                ++j;
            }
            if(left == right)
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};