class Solution {
public:
    // long long maxKelements(vector<int>& nums, int k) 
    // {
    //     long long score = 0;
    //     while(k != 0)
    //     {
    //         int maxIndex = max_index(nums);
    //         score += nums[maxIndex];
    //         nums[maxIndex] = ceil(nums[maxIndex],3);
    //         --k;
    //     }
    //     return score;
    // }

    // int max_index(vector<int>& nums)
    // {   
    //     int max = nums[0];
    //     int maxIndex = 0;
    //     for(int i = 1; i < nums.size(); ++i)
    //     {
    //         if(nums[i] > max)
    //         {
    //             max = nums[i];
    //             maxIndex = i;
    //         }
    //     }
    //     return maxIndex;
    // }

    long long maxKelements(std::vector<int>& nums, int k) 
    {
        long long score = 0;
        
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        while (k > 0) 
        {
            int max = maxHeap.top();
            maxHeap.pop();
            
            score += max;
            
            maxHeap.push(ceil(max,3));
            --k;
        }
        
        return score;
    }
    
    int ceil(int a, int b)
    {
        return (a + b - 1) / 3;
    }

};
