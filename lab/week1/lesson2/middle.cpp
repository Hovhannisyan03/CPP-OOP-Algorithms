#include <iostream>

int main()
{
    const size_t size = 6;
    int arr[size];
    int mid = 0;
    std::cout << "Enter array elements: ";
    for(int i = 0; i < size; ++i)
    {   
	std::cin >> arr[i];
	mid += arr[i];
    }
    mid = mid / size;
    std::cout << mid << std::endl;
    return 0;
}
