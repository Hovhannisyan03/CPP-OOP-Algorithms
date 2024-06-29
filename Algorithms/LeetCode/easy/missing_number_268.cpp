class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int m_number = (nums.size() * (nums.size() + 1)) / 2;
        for(auto& elem : nums)
        {
            m_number -= elem;
        }

        return m_number;
    }
};
