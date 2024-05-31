#include <iostream>


int b_search(int arr[], size_t first, size_t end, int target)
{
    int mid = first + (end - first) / 2;
    
    if(first > end)
    {
        return -1;
    }
    else if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid] > target)
    {
        return b_search(arr,first,mid - 1,target);
    }
    else 
    {
        return b_search(arr,mid + 1,end,target);
    }
}

int main()
{   
    const size_t size = 7;
    int arr[size];
    std::cout << "Enter arr: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int num = 0;
    std::cout << "Enter target: ";
    std::cin >> num;

    std::cout << "Index: " << b_search(arr,0,size-1,num) << std::endl;

    return 0;
}
