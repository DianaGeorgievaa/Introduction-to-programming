#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{
    cout<<"If you want to stop the program enter a negative number or 0!"<<endl;
    int first_num, second_num, y;
    cout<<"Please, enter the sequence:"<<endl;
    // Reads the sequence
    cin>>first_num;
    cin>>second_num;
    y=second_num;
    // Checks if the sequence is undefined
    if (first_num==second_num)
     {
         cout<<"Undefined";
     }
    else
    {
        while(second_num>0)
    {
     first_num=y;
     y=second_num;
     cin>>second_num;
     {
        if (y==second_num)
         {
             cout<<"Undefined"<<endl; break;
         }
     }
    if(first_num<y)
        {
            cout<<"Ascending"<<endl;
        }
     else if (first_num>y)
        {
            cout<<"Descending"<<endl;
        }
}
}

return 0;
    }
