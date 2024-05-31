class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int lower = 0;
        int right = nums.size();

        while (lower < right) 
        {
            int mid = lower + (right - lower) / 2;
            if (nums[mid] < 0) 
            {
                lower = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }

        int upper = 0;
        right = nums.size();
        while (upper < right) 
        {
            int mid = upper + (right - upper) / 2;
        
            if (nums[mid] <= 0) 
            {
                upper = mid + 1;
            } 
            else 
            {
                right = mid;
            }
        }
        return nums.size() - upper > lower ? nums.size() - upper : lower;
    }
};