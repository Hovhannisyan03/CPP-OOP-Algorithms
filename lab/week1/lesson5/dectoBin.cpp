#include <iostream>

void to_binary(int num)
{   
    const size_t size = sizeof(int) * 8;
    int arr[size] = {};
    int index = 0;
    while(num != 0)
    {
        if(num % 2 == 0)
	{
	    arr[index] = 0;
	    ++index;
	}
	else 
	{
	    arr[index] = 1;
	    ++index;
	}
	num /= 2;
    }  
    
    for(int i = size - 1; i >= 0; --i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;

    to_binary(num);
}
