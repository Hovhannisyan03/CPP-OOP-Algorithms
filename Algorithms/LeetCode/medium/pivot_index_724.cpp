class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        // vector<int> prefix(nums.size(),0);
        // vector<int> postfix(nums.size(),0);

        // for(int i = 1; i < nums.size(); ++i)
        // {
        //     prefix[i] = prefix[i - 1] + nums[i - 1];
        // }

        // for(int i = nums.size()-2; i >= 0; --i)
        // {
        //     postfix[i] = postfix[i + 1] + nums[i + 1];
        // }

        // for(int i = 0; i < prefix.size(); ++i)
        // {
        //     if(prefix[i] == postfix[i])
        //     {
        //         return i;
        //     }
        // }

        int totalSum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            totalSum += nums[i];
        }

        int leftSum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {   
            int rightSum = totalSum - leftSum - nums[i];//calculate rightSum

            if(leftSum == rightSum)
            {
                return i;
            }
            leftSum += nums[i];//update leftSum
        }
        return -1;
    }
};
