int solution(string fileSystem) 
{
    if(fileSystem[0] != '\f') fileSystem = "\f" + fileSystem;
    fileSystem += "\f";
    int n = fileSystem.size();
    stack<int> S;
    int maximum = 0;
    int i = 0;
    while(i < n)
    {
        i++;
        //count tabs
        int tabs = 0;
        while(i < n && fileSystem[i] == '\t')
        {
            i++;
            tabs++;
        }

        //count lenght of name
        int len = 0;
        bool isFile = false;
        while(i < n && fileSystem[i] != '\f'){
            len++;
            if( fileSystem[i] == '.') 
            {
                isFile = true;   
            }
            i++;
        }

        // backtrack depth
        while(!S.empty() && S.size() > tabs)
        {
            S.pop();
        }

        int total = 0;
        if(!S.empty())
        {
            total += S.top();
        }
        
        total += len + 1;
        if(isFile)
        {
            maximum = max(maximum, total - 1);
        }
        S.push(total);
    }
    return maximum;
}
