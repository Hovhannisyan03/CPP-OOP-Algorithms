class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        long long max1 = LLONG_MIN;  //use llong_min to handle cases where INT_MIN is in the array
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        
        for (int elem : nums) 
        {
            if (elem == max1 || elem == max2 || elem == max3) 
            {
                continue;
            }
            if (elem > max1) 
            {
                max3 = max2;
                max2 = max1;
                max1 = elem;
            } 
            else if (elem > max2) 
            {
                max3 = max2;
                max2 = elem;
            } 
            else if (elem > max3) 
            {
                max3 = elem;
            }
        }
        
        return max3 == LLONG_MIN ? max1 : max3;
    }
};
