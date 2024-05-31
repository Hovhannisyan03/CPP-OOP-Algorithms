#include <iostream>

int *insert(int *, int);

int *insert(int*, int , int);

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
    std::cout << "Enter position you want to insert: ";
    do
    {
        std::cin >> pos;
    }while(pos >= size);

    int *Parr1 = insert(arr1,size);
    int *Parr2 = insert(arr2,size,pos);
    
    std::cout << "First array after insert: ";
    for(int i = 0; i < size+1; ++i)
    {
        std::cout <<  Parr1[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Second array after insert: ";

    for(int i = 0; i < size+1; ++i)
    {
        std::cout << Parr2[i] << " ";
    }
    std::cout << std::endl;
    delete[]Parr1;
    delete[]Parr2;

    return 0;
}

int *insert(int* arr, int size)
{
    int num = 0;
    std::cout << "Enter number you want to insert end of array: ";
    std::cin >> num;
    int *Narr = new int[size+1];
    for(int i = 0; i < size+1; ++i)
    {
        if(i == size)
	{
	    Narr[i] = num;
	    break; 
	}
        Narr[i] = arr[i];
    }
    delete []arr;
    arr = Narr;
    return arr;
}


int *insert(int* arr, int size, int pos)
{
    int num = 0;
    std::cout << "Enter number you want to insert: ";
    std::cin >> num;
    int *Narr = new int[size+1];
    for(int i = 0, j = 0; i < size+1; ++i)
    {
        if(i == pos)
	{
	    Narr[i] = num;
	    continue;
	}
        Narr[i] = arr[j];
	++j;
    }
    delete []arr;
    arr = Narr;
    return arr;
}