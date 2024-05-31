class Solution {
private:
    unordered_map<int, vector<int>> indexMap;
public:
    Solution(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); ++i) 
        {
            indexMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> index = indexMap[target];
        
        int randomIndex = rand() % index.size();

        return index[randomIndex];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */