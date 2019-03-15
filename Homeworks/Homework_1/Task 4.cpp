#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{   int secondNumber, firstNumber, minNumber;
    cin>>firstNumber;
   
 while(firstNumber>0) 
 {
     cin>>second_num;
     minNumber=min(firstNumber, secondNumber);

  while(minNumber>0)
     {
         while(secondNumber>0)
     {
         minNumber=min(minNumber,secondNumber);
         cin>>secondNumber;
     }
     cout<<minNumber;
     break;
     }
   break;
 }
return 0;

}
