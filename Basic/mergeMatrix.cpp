#include <iostream>

int main()
{
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;
    int **matrix1 = new int*[size];
    int **matrix2 = new int*[size];
    
    for(int i = 0; i < size; ++i)
    {
       matrix1[i] = new int[size];
       matrix2[i] = new int[size];
    }

    std::cout << "Enter first matrix elements " << size << "x" << size << "\n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          std::cin >> matrix1[i][j];
       }
    }

    std::cout << "Enter second matrix elements " << size << "x" << size << "\n";
    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          std::cin >> matrix2[i][j];
       }
    }

    int **merge = new int*[2*size];
    for(int i = 0; i < 2*size; ++i)
    {
       merge[i] = new int[size];
    }
    
    int row = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
	{
	   merge[row][j] = matrix1[i][j];
	}
	++row;
    }

    for(int i = 0; i < size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          merge[row][j] = matrix2[i][j];
       }
       ++row;
    }
    
    std::cout << "Combinated\n";
    for(int i = 0; i < 2*size; ++i)
    {
       for(int j = 0; j < size; ++j)
       {
          std::cout << merge[i][j] << " ";
       }
       std::cout << std::endl;
    }
    
    for(int i = 0; i < size; ++i)
    {
       delete [] matrix1[i];
       delete [] matrix2[i];
    }

    for(int i = 0; i < 2*size; ++i)
    {
       delete [] merge[i];
    }

    delete []matrix1;
    delete []matrix2;
    delete []merge;
    
    return 0; 
}