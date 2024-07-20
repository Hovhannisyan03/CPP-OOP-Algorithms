int solution(int year) 
{
    if(year >= 1 && year <= 2005)
    {
        if(year % 100 == 0)
        {
            return year / 100;
        }
        else 
        {
            return year / 100 + 1;
        }
    }
}
