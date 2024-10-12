class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int size = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < size; ++i)
        {
            if(maxIndex >= size - 1)
            {
                return true;
            }
            else if(maxIndex == i && nums[i] == 0)
            {
                return false;
            }
            maxIndex = maxIndex > i + nums[i] ? maxIndex : i + nums[i];
        }
        return true;
    }
};
