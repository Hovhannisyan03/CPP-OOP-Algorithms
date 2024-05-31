#include <iostream>
#include <string.h>

int main()
{
    int size = 0;

    std::cout << "Enetr strings size: ";
    std::cin >> size;

    char *str1 = new char[size];
    char *str2 = new char[size];

    std::cout << "Enter first string: ";
    std::cin.get();
    std::cin.getline(str1, size);

    std::cout << "Enter second string: ";
    std::cin.getline(str2, size);
    
    if (strlen(str1) != strlen(str2))
    {   
	std::cout << "False" << std::endl;
        return 0;
    }

    for(int i = 0; i < strlen(str1); ++i)
    {
       for(int j = 0; j < strlen(str1); ++j)
       {
          if(str1[i] > str1[j])
	  {
	     char temp = str1[j];
	     str1[j] = str1[i];
	     str1[i] = temp;
	  }
       }
    }
    for(int i = 0; i < strlen(str1); ++i)
    {
       for(int j = 0; j < strlen(str1); ++j)
       {
          if(str2[i] > str2[j])
	  {
	     char temp = str2[j];
	     str2[j] = str2[i];
	     str2[i] = temp;
	  }
       }
    } 

    int count = 0;
    for(int i = 0; i < strlen(str1); ++i)
    {
       if(str1[i] == str2[i])
       {
          count++;
       }
    }
    
    if(count == strlen(str1)) 
    {
       std::cout << "True" << std::endl;
    }
    else 
    {
       std::cout << "False" << std::endl;
    }
   
   delete []str1;
   delete []str2;
}