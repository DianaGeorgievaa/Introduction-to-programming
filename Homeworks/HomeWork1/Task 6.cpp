#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{   
    char symbol;
    cin>>symbol;
    int numberOfRows;
   
    cout << "Enter number of rows: ";
    cin >> numberOfRows;

if (numberOfRows>25)
    {
        cout<<"Error! Incorrect input";
    }
else
{
    for ( int i=1; i<=numberOfRows; i++)
    {
        for (int j=1; j<=numberOfRows-i; j++) 
        cout<<" ";
        {
         for (int j=1; j<=i; j++) cout<< symbol <<" ";
         {
            cout<<endl;
         }
        }
    }
}
return 0;
}
