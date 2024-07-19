vector<vector<int>> solution(vector<vector<int>> a) 
{
    int size = a.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = i; j < size - 1 - i; ++j)
        {
            
            int tmp = a[i][j];
            a[i][j] = a[size - 1 - j][i];
            a[size - 1 - j][i] = a[size - 1 - i][size - 1 - j];
            a[size - 1 - i][size - 1 - j] = a[j][size - 1 - i];
            a[j][size - 1 - i] = tmp;
        }   
    }
    return a;
}
