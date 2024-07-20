bool solution(int n) 
{
    int count_of_digit = 0;
    int temp = n;
    while(temp)
    {
        ++count_of_digit;
        temp /= 10;
    }
    
    temp = count_of_digit;
    int first_half = 0;
    int second_half = 0;
    int half = 2;

    while(n)
    {
        switch(half)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                first_half += n % 10;
                n /= 10;
                --count_of_digit;
                if(count_of_digit == 0)
                {
                    half = 0;
                }
                break;
            }
            case 2:
            {
                second_half += n % 10;
                n /= 10;
                --count_of_digit;
                if(count_of_digit == temp/2)
                {
                    half = 1;
                }
            }
        }
    }
    return first_half == second_half;
}
