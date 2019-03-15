#include  <iostream>
#include  <cstdlib>
#include <iomanip>

using  namespace  std;

int main()
{
    unsigned int sec;
    cout<<"Please, enter secundes"<<endl;
    cin>>sec;
    if(sec>0 && sec<24*3600)
    {   int minutes=(sec%3600)/60; // Converts sec to minutes
        int hours=sec/3600;       // Converts sec to hours
        cout<<"HH:MM"<<" ";
        cout<<setfill('0')<<setw(2)<<hours<<":";
        cout<<setfill('0')<<setw(2)<<minutes<<endl;
    }
return 0;
}
