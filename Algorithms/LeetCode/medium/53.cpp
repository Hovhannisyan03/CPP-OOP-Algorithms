class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int overallMaxSum = nums[0];
        int currentMaxSum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            currentMaxSum = nums[i] > nums[i] + currentMaxSum ? nums[i] : nums[i] + currentMaxSum;
            overallMaxSum = currentMaxSum > overallMaxSum ? currentMaxSum : overallMaxSum;
        }

        return overallMaxSum;       
    }
}; 