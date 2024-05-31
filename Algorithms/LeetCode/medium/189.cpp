class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        size_t size = nums.size();
        if (k == 0 || size == 1 || k == size) 
        {
            return;
        }
        k = k % size;
       
        size_t i = 0;
        size_t j = size - k - 1; 
        
        while (i < j) 
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }

        i = size - k;
        j = size - 1;
        
        while (i < j) 
        {
           swap(nums[i], nums[j]);
            ++i;
            --j; 
        }

        for (size_t i = 0; i < size / 2; ++i) 
        {
            swap(nums[i], nums[size - i - 1]);
        }
    }
};
