#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int main()
{   // Reads a symbol
    char symbol;
    cin>>symbol;

    int num_rows;
    // Reads the number of the rows
    cout << "Enter number of rows: ";
    cin >> num_rows;

if (num_rows>25)
    {
        cout<<"Error.Incorrect input";
    }
else
{
    for ( int i=1; i<=num_rows; i++)
    {
        for (int j=1; j<=num_rows-i; j++) cout<<" ";
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
