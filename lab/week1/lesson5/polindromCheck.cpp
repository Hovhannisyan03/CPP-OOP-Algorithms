#include <iostream>

int isPol(int num)
{
    int res = 0;
    while(num != 0)
    {
        int digit = num % 10;
	res = (res * 10) + digit;
	num /= 10;
    }

    return res;

}
int polindrom_Check(int num)
{  
   int count = 0;
   while(1){
       if(num == isPol(num))
       {   
	   std::cout << "Result: " << num << std::endl;
           return count;
       }
       ++count;
       std::cout << num << " " << isPol(num) << std::endl; 
       num += isPol(num);
   }
}

int main()
{
    int num = 0;
    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << "Count is: " << polindrom_Check(num) << std::endl;
}
