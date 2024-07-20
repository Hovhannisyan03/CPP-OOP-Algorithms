bool solution(vector<int> sequence) 
{
    int count = 0;
    int current = 0;
    for(int i = 1; i < sequence.size(); ++i)
    {
        if(sequence[current] < sequence[i])
        {
            current = i;
            continue;
        }
        else if(current == 0 && sequence[current] >= sequence[i])
        {
            ++count;
            current = i;
        }
        else if(sequence[current] > sequence[i] && sequence[current-1] < sequence[i])
        {
            current = i;
            ++count;
        }
        else
        {
            ++count;
        }
        if(count > 1)
        {
            return false;
        }
    }
    return true;
}
