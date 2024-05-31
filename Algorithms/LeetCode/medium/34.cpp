class Solution {
public:
    vector<int> searchRange(vector <int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;
        int lower = -1;
        int upper = -1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                lower = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        };

        start = 0;
        end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                upper = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }
        return {lower,upper};
    }
};