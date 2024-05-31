class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int missing = 1;
        int size = arr.size();
        int i = 0;
        while(i <= size - 1)
        {
            if(missing == arr[i])
            {
                ++missing;
                ++i;
                continue;
            }
            else
            {
                --k;
                if(k == 0)
                {
                    return missing;
                }
                ++missing;
            }
        }   
        return missing + k - 1; 
    }
};  