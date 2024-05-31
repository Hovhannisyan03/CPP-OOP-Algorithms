class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int num = 0;
        for(auto elem : nums)
        {
            num ^= elem;
        }
        return num;

    }
};