class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        unordered_set<int> set;
        for(auto& elem : nums1)
        {
            if(!set.contains(elem))
            {
                set.insert(elem);
            }
        }    
        for(auto& elem : nums2)
        {
            if(set.contains(elem))
            {
                result.push_back(elem);
                set.erase(elem);
            }
        }
        return result;
    }
};
