#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{   int second_num, first_num, min_num;
    cin>>first_num;

    while(first_num>0) // Stops if the number is <= 0
 {
     cin>>second_num;
     min_num=min(first_num, second_num);

  while(min_num>0)
     {
         while(second_num>0)
     {
         min_num=min(min_num,second_num);
         cin>>second_num;
     }
     cout<<min_num;
     break;
     }
   break;
 }
return 0;

}
