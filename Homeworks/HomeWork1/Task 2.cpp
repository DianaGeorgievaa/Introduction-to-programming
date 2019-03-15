#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{   
    int number;
    cout<<"Please enter a positive number"<<endl;
    cin>>number;
    int newNumber=0;
    int n;
    do
    {
        n=number%10;
        newNumber=newNumber*10+n;
        number=number/10;
    }
    while(number>0);
    {
    cout<<hex<<newNumber<<endl;
    }
return 0;

}
