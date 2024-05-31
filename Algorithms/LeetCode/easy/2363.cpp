class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        std::unordered_map<int, int> valueToWeight;

        for (const auto& item : items1) 
        {
            valueToWeight[item[0]] += item[1];
        }

        for (const auto& item : items2) 
        {
            valueToWeight[item[0]] += item[1];
        }

        std::vector<std::vector<int>> ret;
        for (const auto& pair : valueToWeight) 
        {
            ret.push_back({pair.first, pair.second});
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};