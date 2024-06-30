class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {       
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] *= nums[i];
        }

        int first = 0;
        int last = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if(nums[first] >= nums[last])
            {
                result[i] = nums[first++];
            }
            else
            {
                result[i] = nums[last--];
            }
        }
        return result;
    }
};
