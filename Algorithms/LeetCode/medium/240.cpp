class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t size = matrix.size();
        size_t col = matrix[0].size();
        for(size_t i = 0; i < size; ++i)
        {
            if(target >= matrix[i][0] && target <= matrix[i][col - 1])
            {   
                size_t s = 0;
                size_t e = col - 1;
                while(s <= e)
                {
                    size_t mid = s + (e - s) / 2;
                    if(matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if(matrix[i][mid] < target)
                    {
                        s = mid + 1;
                    }
                    else
                    {
                        e = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};