#include  <iostream>
#include  <cstdlib>
#include <math.h>

using  namespace  std;

int main()
{   
    int number, swapNumber;
    int firstDigit, lastDigit, digits;

    cout<<"Please, enter a number:"<<endl;
    cin>>number;

    lastDigitt=number%10; 
    digits= log10(number); 
    first_digit=(number/pow(10,digits)); 

    swapNumber=lastDigit;
    swapNumber=swapNumber*pow(10,digits);
    swapNumber=swapNumber+number%((int)pow(10,digits));
    swapNumber=swapNumber-lastDigit;
    swapNumber=swapNumber+firstDigit;

    cout<<"The number after swapping is:"<<swapNumber<<endl;

return 0;

}
