class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while(mid <= end)
        {
            if(nums[mid] == 0)
            {
                int tmp = nums[start];
                nums[start] = nums[mid];
                nums[mid] = tmp;
                ++start;
                ++mid;
            }
            else if(nums[mid] == 1)
            {
                ++mid;
            }
            else 
            {
                int tmp = nums[mid];
                nums[mid] = nums[end];
                nums[end] = tmp;
                --end;
            }
        }
        for(auto elem : nums)
        {
            std::cout << elem;
        }
    }
};