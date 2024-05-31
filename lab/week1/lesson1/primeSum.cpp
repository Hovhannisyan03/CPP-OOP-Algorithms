#include <iostream>

int main()
{
    const size_t size = 10;
    int arr[size];
    std::cout << "Enter array elemnts (" << size << "): " << std::endl;
    
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    int sum = 0;
    int count1 = 0;
    for(int i = 0; i < size; ++i)
    {   
	int count = 0;
        for(int j = 2; j <= arr[i]/2; ++j)
	{
	    if(arr[i] % j == 0)
	    {
	        ++count;
	    }
	}
	if(count == 0)
	{
	   sum += arr[i];
	   ++count1;
	}
    }
    std::cout << "Sum: " << sum/count1 << std::endl;
}
