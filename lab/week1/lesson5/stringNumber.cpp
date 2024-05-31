#include <iostream>

void all_Numbers(char* arr)
{   
    size_t i = 0;
    while(arr[i] != '\0')
    {
        if(arr[i] >= '0' && arr[i] <= '9')
	{
	    std::cout << arr[i] << " ";
	}
	++i;
    }

    return;
}

int main()
{
    const size_t size = 20;
    char arr[size];
    std::cout << "Enter arr: ";
    std::cin.getline(arr,20);

    all_Numbers(arr);
    
    return 0;
}
