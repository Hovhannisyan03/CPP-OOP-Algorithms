class Solution {
 public:
    int majorityElement(vector<int>& nums) 
    {
        int majority = 0;
        int count = 0;
        for (const int num : nums) 
        {
            if(count == 0)
            {
                majority = num;
            }
            count += num == majority ? 1 : -1;
        }
        return majority;
    }
};
