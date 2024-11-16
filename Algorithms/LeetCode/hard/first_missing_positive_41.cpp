class Solution {
public:
    // int firstMissingPositive(vector<int>& nums) 
    // {
    //     int missing = 1;
    //     int min = nums[0];
    //     int max = nums[0];
    //     for(int i = 0; i < nums.size(); ++i)
    //     {
    //         max = max > nums[i] ? max : nums[i];
    //         std::cout << min << " " << missing << std::endl;
    //         if(nums[i] == missing)
    //         {
    //             if((min - missing != missing) && (min - missing > 0))
    //             {
    //                 missing = min - 1;
    //             }
    //             else
    //             {
    //                 missing = max + 1;
    //             }
    //         }
    //         min = min > nums[i] && nums[i] > 0 ? nums[i] : min;
    //     }
    //     return missing;
    // }
    int firstMissingPositive(std::vector<int>& nums) 
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) 
        {
            if (nums[i] != i + 1) 
            {
                return i + 1;
            }
        }

        return n + 1; 
    }
};