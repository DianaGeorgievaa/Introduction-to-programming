#include  <iostream>
#include  <cstdlib>
#include <math.h>

using  namespace  std;

int main()
{   int num, swap_num;
    int first_digit, last_digit, digits;

    //Reads a number
    cout<<"Please, enter a number:"<<endl;
    cin>>num;

    last_digit=num%10; // Gets the last digit
    digits= log10(num); // Gets the digits-1
    first_digit=(num/pow(10,digits)); // Gets the first digit

    swap_num=last_digit;
    swap_num=swap_num*pow(10,digits);
    swap_num=swap_num+num%((int)pow(10,digits));
    swap_num=swap_num-last_digit;
    swap_num=swap_num+first_digit;

    cout<<"The number after swapping is:"<<swap_num<<endl;

return 0;

}
