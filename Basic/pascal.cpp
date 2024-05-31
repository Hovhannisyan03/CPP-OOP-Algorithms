
#include <iostream>
#include <cstdlib>

int main()
{
    int row = 0;
    std::cout << "Enter row: ";
    std::cin >> row;
    int **arr = (int**)malloc(row*sizeof(int*));
    int column = 0;
    for(int i = 0; i < row; ++i)
    {  
       ++column;
       arr[i] = (int*)malloc(sizeof(int)*column);
    }
    
    column = 0;
    for(int i = 0; i < row; ++i)
    { 
       ++column;
       for(int j = 0; j < column; ++j)
       { 
          if(column == 1)
	  {  
             arr[i][j] = 1;
	     std::cout << arr[i][j];
	  }
	  else if(column == 2)
	  {
	     arr[i][j] = 1;
	     std::cout << arr[i][j] << " ";
	  }
	  else 
	  {  if(j == 0){
	        arr[i][0] = 1;
	        std::cout << arr[i][0] << " ";
	     }
	     else if(j == column - 1){
	        arr[i][column-1] = 1;
		std::cout << arr[i][column-1];
	     }
	     if (j != 0 && j != column-1)
	     {  
	        arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
		std::cout << arr[i][j] << " ";
	     }
	  }
       } 
       std::cout << std::endl;
    }
    
    column = 0;
    for (int i = 0; i < row; ++i)
    {   ++column;
  	free(arr[0]);
    }

    free(arr);
}
