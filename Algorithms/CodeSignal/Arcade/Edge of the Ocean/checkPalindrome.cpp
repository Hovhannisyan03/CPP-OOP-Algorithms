bool solution(string inputString) {
    int size = inputString.length() - 1;
    
    for(int i = 0; i <= size/2; ++i)
    {
        if(inputString[i] == inputString[size-i])
        {   
            continue;
        }
        else 
        {
            return false;
        }
    }
    return true;
}
