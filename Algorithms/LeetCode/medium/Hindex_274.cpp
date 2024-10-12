class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        
        int hInd = 0;
        for (int i = 0; i < citations.size(); ++i) 
        {
            if (citations[i] >= i + 1) 
            {
                hInd = i + 1;
            } 
            else 
            {
                break;
            }
        }
        return hInd;
    }
};
