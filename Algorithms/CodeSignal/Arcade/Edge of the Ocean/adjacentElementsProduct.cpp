int solution(vector<int> inputArray) 
{
    int max = INT_MIN;
    int current_product = 0;
    for(int i = 0; i < inputArray.size() - 1; ++i)
    {
        current_product = inputArray[i] * inputArray[i+1];
        max = max < current_product ? current_product : max;
    }
    return max;
}
