#include <iostream>

int main()
{
    const size_t size = 7;
    int arr[size];
    std::cout << "Enter array elements(" << size << "): ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int sum = 0;

    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] % 2 == 1)
	{
	    sum += arr[i];
	}
    }

    std::cout << "Sum: " << sum << std::endl;
}
