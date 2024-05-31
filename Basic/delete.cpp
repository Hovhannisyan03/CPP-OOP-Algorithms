#include <iostream>
#include <stdlib.h>

int *del(int *, int);

int *del(int *, int , int);
int main()
{
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;

    int *arr1 = new int[size];
    int *arr2 = new int[size];

    std::cout << "Enter first array elements: ";
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr1[i];
    }

    std::cout << "Enter second array elements: ";
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr2[i];
    }
    int pos = 0;
    std::cout << "Enter position you want ot delete: ";
    std::cin >> pos;
    int *Parr1 = del(arr1,size);
    int *Parr2 = del(arr2,size,pos);
    
    std::cout << "First array after delete: ";
    for(int i = 0; i < size-1; ++i)
    {
        std::cout <<  Parr1[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Second array after delete: ";
    for(int i = 0; i < size-1; ++i)
    {
        std::cout << Parr2[i] << " ";
    }
    std::cout << std::endl;
    delete[]Parr1;
    delete[]Parr2;

    return 0;
}


int *del(int *arr, int size)
{
    for(int i = 0; i < size-1; ++i)
    {
        arr[i] = arr[i+1];
    }
    arr = (int*)realloc(arr, size - 1);
    return arr;
}

int *del(int *arr, int size, int pos)
{
    for(int i = 0; i < size; ++i)
    {
        if(i >= pos)
	{
	    arr[i] = arr[i+1];
	}
    }
    arr = (int*)realloc(arr, size - 1);
    return arr;
}