#include <iostream>

int main()
{
    const size_t size = 7;
    int arr[size];
    int sum = 0;
    int mul = 1;
    std::cout << "Enter array elements(" << size << "): " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
	sum += arr[i];
	mul *= arr[i];
    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Mul: " << mul << std::endl;
    return 0;
}
