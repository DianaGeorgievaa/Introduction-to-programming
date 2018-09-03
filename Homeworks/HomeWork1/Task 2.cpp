#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{    // Reads a number
    int number;
    cout<<"Please enter a positive number"<<endl;
    cin>>number;
    int new_num=0;
    int n;
    do
    {
        // Swaps the numbers
        n=number%10;
        new_num=new_num*10+n;
        number=number/10;
    }
    while(number>0);
    // Converts to hex.
    {
    cout<<hex<<new_num<<endl;
    }
return 0;

}
