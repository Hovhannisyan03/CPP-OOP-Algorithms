bool solution(vector<vector<char>> grid) 
{
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> sub_grid[3][3];
    
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            
            if(grid[i][j] != '.')
            {
                if(row[i].count(grid[i][j]) || col[j].count(grid[i][j]) || sub_grid[i/3][j/3].count(grid[i][j]))
                {
                    return false;
                }
            }
            row[i].insert(grid[i][j]);
            col[j].insert(grid[i][j]);
            sub_grid[i/3][j/3].insert(grid[i][j]);
        }
    }
    return true;
}
