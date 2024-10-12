class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {   
        int size = nums.size();
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 2; ++i)
        {
            int j = i + 1;
            int k = size - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    while(j < k && nums[j] == nums[j - 1])
                    {
                        ++j;
                    }
                    while(j < k && nums[k] == nums[k + 1])
                    {
                        --k;
                    }
                }
                else if(sum > 0)
                {
                    --k;
                }
                else
                {
                    ++j;
                }
                while(i < size - 1 && nums[i] == nums[i + 1])
                {
                    ++i;
                }
            }
        }
        return result;
    }
};
