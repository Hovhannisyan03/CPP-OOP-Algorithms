class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currentSubArray = nums[0];
        int maxSubArray = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            currentSubArray = nums[i] > nums[i] + currentSubArray ? nums[i] : nums[i] + currentSubArray;
            maxSubArray = currentSubArray > maxSubArray ? currentSubArray : maxSubArray;
        }

        return maxSubArray;       
    }
}; 
