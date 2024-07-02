class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count_of_elements;
        unordered_map<int, int> first_index;
        unordered_map<int, int> last_index;

        for (int i = 0; i < nums.size(); ++i) 
        {
            if (!first_index.count(nums[i])) 
            {
                first_index[nums[i]] = i;
            }
            last_index[nums[i]] = i;
            count_of_elements[nums[i]]++;
        }

        int max_degree = 0;
        for (auto& pair : count_of_elements) 
        {
            max_degree = max(max_degree, pair.second);
        }

        int min_length = nums.size();
        for (auto& pair : count_of_elements) 
        {
            if (pair.second == max_degree) {
                min_length = min(min_length, last_index[pair.first] - first_index[pair.first] + 1);
            }
        }

        return min_length;
    }
};
