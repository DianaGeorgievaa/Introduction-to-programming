#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{
    cout<<"If you want to stop the program enter a negative number or 0!"<<endl;
    int firstNumber, secondNumber, y;
    cout<<"Please, enter the sequence:"<<endl;
    cin>>firstNumber;
    cin>>secondNumber;
    y=secondNumber;
    if (firstNumber==secondNumber)
     {
         cout<<"Undefined";
     }
    else
    {
        while(secondNumber>0)
    {
     firstNumber=y;
     y=secondNumber;
     cin>>secondNumber;
     {
        if (y==secondNumber)
         {
             cout<<"Undefined"<<endl; 
             break;
         }
     }
    if(firstNumber<y)
        {
            cout<<"Ascending"<<endl;
        }
     else if (firstNumber>y)
        {
            cout<<"Descending"<<endl;
        }
}
}

return 0;
    }
